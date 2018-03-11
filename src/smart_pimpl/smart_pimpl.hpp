//
// Pimpl.hpp
// Created by simon on 6/03/18.
//

#ifndef SMART_PIMPL_SMART_PIMPL_HPP
#define SMART_PIMPL_SMART_PIMPL_HPP

#include <memory>

namespace SmartPimpl {
    template<typename T>
    requires sizeof(T) > 0 && !std::is_array_v<T>
    auto default_delete(T *pimpl) -> void
    {
        delete pimpl;   // NOLINT
    }

    template<typename T>
    using Deleter = void (*)(T *);

    template <typename T>
    using Reference = std::shared_ptr<T>;

    template <typename T>
    using Entity = std::unique_ptr<T, Deleter<T>>;

    template<typename Interface,
             template<typename>
             typename Policy>
    class Base {
    public:
        struct Impl;

    protected:
        using Ptr = Policy<Impl>;

        constexpr Base() noexcept : impl_{ null_impl() } {}
        explicit Base(Ptr impl) noexcept : impl_{ std::move(impl) } {}

        template<typename ...Args>
        explicit Base(Args &&...args) : impl_{ make_impl_of<Impl>(args...) } {}

        template<typename T = Impl, typename ...Args>
        static auto make_impl_of(Args &&...args) -> Ptr
        {
            return Ptr(new T(std::forward<Args>(args)...), default_delete<Impl>);
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

        inline constexpr auto null_impl() -> Ptr
        {
            if constexpr (std::is_same_v<Ptr, std::unique_ptr<Impl, Deleter<Impl>>>) {
                return Ptr(nullptr, nullptr);
            } else {
                return Ptr();
            }
        }
    };
}

#endif // SMART_PIMPL_SMART_PIMPL_HPP
