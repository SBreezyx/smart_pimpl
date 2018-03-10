//
// pimpl.hpp
// Created by simon on 6/03/18.
//

#ifndef SMART_PIMPL_PIMPL_HPP
#define SMART_PIMPL_PIMPL_HPP

#include <memory>

namespace smart_pimpl {
    template<typename T>
    using Deleter = void (*)(T *);

    template<typename T>
    using Copier  = T *(*)(const T *, T *);

    template<typename T>
    requires sizeof(T) > 0 && !std::is_array_v<T>
    auto default_delete(T *pimpl) -> void
    {
        delete pimpl;   // NOLINT
    }

    template<typename>
    struct pimpl {
        struct Impl;

        /* Forward declarations of main classes */
        template<typename/* Policy<>*/>
        class Base;

        /* Convenience typedefs for users. Add more as needed. */
        using Entity    = Base<std::unique_ptr<Impl, Deleter<Impl>>>;

        using Reference = Base<std::shared_ptr<Impl>>;
    };

    template<typename Interface>
    template<typename Policy>
    class pimpl<Interface>::Base {
    protected:
        using Impl = pimpl<Interface>::Impl;
        using Ptr = Policy;

        constexpr Base() noexcept : impl_{ nullimpl() } {}
        explicit Base(Ptr impl) noexcept : impl_{ std::move(impl) } {}

        template<typename ...Args>
        explicit Base(Args &&...args) : impl_{ make_impl_of<Impl>(args...) } {}

        template<typename T = Impl, typename ...Args>
        static auto make_impl_of(Args &&...args) -> Ptr
        {
            return Policy(new T(std::forward<Args>(args)...), default_delete<Impl>);
        }

        auto impl() const -> Ptr&
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

            return impl_;
        }

        /*
         * Switch out the implementation with another (possibly derived) implementation!
         */
        auto reset(Ptr new_impl) -> void
        {
            impl_ = std::move(new_impl);
        }

    private:
        mutable Ptr impl_;

        inline constexpr auto nullimpl() -> Ptr
        {
            if constexpr (std::is_same_v<Policy, std::unique_ptr<Impl, Deleter<Impl>>>) {
                return Ptr(nullptr, nullptr);
            } else {
                return Ptr();
            }
        }
    };
}

#endif // SMART_PIMPL_PIMPL_HPP
