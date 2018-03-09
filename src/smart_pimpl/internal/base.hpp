//
// Created by simon on 8/03/18.
//

#ifndef SMART_PIMPL_BASE_HPP
#define SMART_PIMPL_BASE_HPP

namespace smart_pimpl {

    template<typename Interface>
    template<typename Ptr>
    class pimpl<Interface>::Base {
    protected:
        using Impl = pimpl<Interface>::Impl;

        Base() requires std::is_same_v<Ptr, pimpl<Interface>::ReferencePtr> = default;

        Base() requires std::is_same_v<Ptr, pimpl<Interface>::EntityPtr> : impl_(nullptr, nullptr) {}

        Base(Ptr impl) :
            impl_{ std::move(impl) }
        {}

        template<typename ...Args>
        explicit Base(Args &&...args) : impl_{ make_ptr<Ptr, Impl>(args...) }
        {}

        Ptr &impl()
        {
            /* This `if` is only entered we were default constructed from an argumentless
             * constructor, such as the compiler generated one or an explicit user-defined one.
             * We must now lazily instantiate the impl_ptr, which can only default construct the
             * implementation. Luckily, if the interface declares a default constructor, but forgets
             * to define one for the implementation (so now there's a mismatch between constructors),
             * then the program won't compile because overload resolution will fail.
             */
            if (impl_ == nullptr) {
                impl_ = make_ptr<Ptr, Impl>();
            }

            return impl_;
        }

    private:
        mutable Ptr impl_;
    };
}

#endif //SMART_PIMPL_BASE_HPP
