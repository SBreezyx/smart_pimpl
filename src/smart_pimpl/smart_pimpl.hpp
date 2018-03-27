//
// Pimpl.hpp
// Created by simon on 6/03/18.
//

#ifndef SMART_PIMPL_SMART_PIMPL_HPP
#define SMART_PIMPL_SMART_PIMPL_HPP

#include <type_traits>
#include <memory>

namespace SmartPimpl {
    /**
     * Deleter - a convenience typedef for the type of a deleter for SmartPimpl.
     *
     * @tparam T - the implementation to delete.
     */
    template<typename T>
    using Deleter = void (*)(T *);

    /**
     * SmartPimpl::default_delete.
     * This helper function stands in for any smart pointer that takes a custom deleter
     * but with the added benefit that it only gets instantiated when constructing the smart pointer.
     * This fact is used to make sure only complete types get instantiated (which should happen only
     * in a class' implementation.
     * @tparam T - the Class implementation struct. Constrained by not being an array (unsupported) and being complete
     * @param pimpl [in] - pointer the implementation to be deleted.
     */
    template<typename T>
    // TODO: Uncomment this when C++20 is released
    // requires sizeof(T) > 0 && !std::is_array_v<T>
    auto default_delete(T *pimpl) -> void
    {
        static_assert(!std::is_array_v<T>);
        static_assert(sizeof(T) > 0);
        delete pimpl;   // NOLINT
    }

    /**
     * Base - the base class which handles all the SmartPimpl magic.
     * When a class derives from Base, it must give the class the policy
     * which it is to use for the pointer (reference and entity semantics are
     * already provided @see Entity and @see Reference).
     *
     * In all translation units that include the interface of a class, they will
     * therefore see that the class has an implementation but they will not be able
     * to use it because it will be an incomplete type. In the implementation of the interface
     * therefore the user must define the implementation before any function attempts to use it
     * as to complete the type. In doing so we now have a perfect split between interface and implementation,
     * and can provide interface and implementation inheritance separately (à la GoF Bridge Pattern).
     *
     * This also provides the benefit of less recompilation when the implementation is a part of the header
     * file and it changes - all affected files don't need to be recompiled, which keeps a stable ABI.
     *
     * To use this class a CRTP-like derivation must be made. When declaring class Foo, this must be written:
     * class Foo : SmartPimpl::[Reference | Entity | <other>]<Foo> { ... };
     * This will generate a completely new type with its own implementation declared (SmartPimpl::<Base><Foo>>::Impl)
     * that must be filled in in the implementation. Naturally, the implementation cannot be abstract.
     * Additionally, the 5 special member functions can remain compiler generated for the interface unless explicitly
     * needed, and an error will occur if the Policy doesn't allow for an operation (e.g. copying an Entity).
     *
     * @tparam Interface - the class using SmartPimpl
     * @tparam Policy - storage policy used. Affects copyablity and movability.
     */
    template<typename Interface,
             template<typename>
             typename Policy>
    class Base {
    public:
        struct Impl;

    protected:
        using Ptr = Policy<Impl>;

        /**
         * Default constructor.
         * Creates a nulled implementation used for lazy instantiation.
         */
        constexpr Base() noexcept : impl_{ null_impl() } {}

        /**
         * Constructor for use with the named constructor idiom.
         * Allows for a static member function to construct different implementations if needed.
         * @param impl - preconstructed implementation.
         */
        explicit Base(Ptr impl) noexcept : impl_{ std::move(impl) } {}

        /**
         * Forwarding constructor used to create an implementation.
         * Instead of having the user handle memory management, they need only call this
         * constructor and the arguments will be diligently forwarded to the appropriate constructor,
         * or fail if no such constructor exists
         *
         * @tparam Args - parameter pack of arguments.
         * @param args - the arguments.
         */
        template<typename ...Args>
        explicit Base(Args &&...args) : impl_{ make_impl_of<Impl>(args...) } {}

        /**
         * make_impl_of, as the name suggests, creates a specific implementation using the Policy with
         * the arguments provided in args. The type of the implementation may not be the regular Impl class,
         * but any such derived class.
         *
         * @tparam T - the implementation to create. Defaults to the top level Impl. @note Impl cannot be abstract.
         * @tparam Args - parameter pack of arguments.
         * @param args- the arugments.
         * @return - a new pointer-to-implementation of type Policy.
         */
        template<typename T = Impl,
                 typename ...Args,
                 typename Constraint = std::enable_if_t<std::is_constructible_v<T, Args...> && std::is_base_of_v<Impl, T>, void>>
        static auto make_impl_of(Args &&...args) -> Ptr
        // TODO: Uncomment this when C++20 is released
        //requires std::is_constructible_v<T, Args...> && std::is_base_of_v<Impl, T>
        {
            return Ptr(new T(std::forward<Args>(args)...), default_delete<Impl>);
        }

        /**
         * impl() - a getter function which is overloaded based on if Impl is default constructible.
         * This paricular overload lazily instantiates the implementation pointer to allow for things such as
         * compiler generated default constructors.
         *
         * @return - the pointer to the implementation.
         */
        template <typename T = Impl>
        auto impl() const -> std::enable_if_t<std::is_default_constructible_v<T>, T*>
        // TODO: Uncomment this C++20 is released. requires std::is_default_constructible_v<Impl>
        {
            /* This `if` is only entered we were default constructed from an argumentless
             * constructor, such as the compiler generated one or an explicit user-defined one.
             * We must now lazily instantiate the impl_ptr, which can only default construct the
             * implementation. Luckily, if the interface declares a default constructor, but forgets
             * to define one for the implementation (so now there's a mismatch between constructors),
             * then the program won't compile because overload resolution will fail.
             */
            if (impl_ == nullptr) {
                impl_ = make_impl_of<Impl>();
            }

            return impl_.get();
        }

        /**
         * impl() - a getter function which is overloaded based on if Impl is default constructible.
         * This particular overload simply returns to the pointer to implementation, and relies on impl_
         * being already constructed.
         *
         * @return
         */
        template <typename T = Impl>
        auto impl() const -> std::enable_if_t<!std::is_default_constructible_v<T>, T*>
        // TODO: Uncomment this C++20 is released. requires !std::is_default_constructible_v<Impl>

        {
            return impl_.get();
        }

    private:
        mutable Ptr impl_;

        /**
         * null_impl - an analogue of nullptr, but assures that the two provided Policies are properly
         * nulled out. This function is used to support default construction generation.
         *
         * @return - a pointer to a nulled implementation.
         */
        inline constexpr auto null_impl() -> Ptr
        {
            if constexpr (std::is_same_v<Ptr, std::unique_ptr<Impl, Deleter<Impl>>>) {
                return Ptr(nullptr, nullptr);
            } else {
                return Ptr();
            }
        }
    };

    /**
     * Reference - a named convenience typedef for classes to derive from.
     * When using Reference the class is said to have `reference` or `pointer` semantics,
     * i.e. the class can share its implementation with other classes it gets copied to
     * (much like a shared pointer).
     *
     * @tparam T - the interface of the class using SmartPimpl (the class which does the derving).
     */
    template <typename T>
    using Reference = Base<T, std::shared_ptr>;

    /**
     * EntityPtr - used in conjunction with Entity
     *
     * @tparam T - the implementation of the class using pointer.
     * @see Entity
     */
    template <typename T>
    using EntityPtr = std::unique_ptr<T, Deleter<T>>;

    /**
     * Entity - a named convenience typedef for classes tp derive from.
     * When a class derived from Entity it is said to have `Entity` semantics,
     * i.e. the class is movable but not copyable -- a step down from singleton.
     *
     * @test T - the interface of the class using SmartPimpl (the which does the deriving).
     */
    template <typename T>
    using Entity = Base<T, EntityPtr>;
}

#endif // SMART_PIMPL_SMART_PIMPL_HPP
