//
// Created by simon on 8/03/18.
//

#ifndef SMART_PIMPL_BASE_HPP
#define SMART_PIMPL_BASE_HPP

namespace smart_pimpl {

    template<typename Interface>
    template<template<typename> typename Policy>
    class pimpl<Interface>::Base {
    protected:
        using Impl = pimpl<Interface>::Impl;
        using Ptr = Policy<Impl>;

        Base() = default;

        template<typename ...Args>
        explicit Base(Args &&...args) : impl_{ make_ptr <Ptr> (args...) }
        {}

        Ptr& impl()
        {
            /* This `if` is only entered we were default constructed from an argumentless
             * constructor, such as the compiler generated one or an explicit user-defined one.
             * We must now lazily instantiate the impl_ptr, which can only default construct the
             * implementation. Luckily, if the interface declares a default constructor, but forgets
             * to define one for the implementation (so now there's a mismatch between constructors),
             * then the program won't compile because overload resolution will fail.
             */
            if (impl_ == nullptr) {
                impl_ = make_ptr<Policy<Impl>>();
            }

            return impl_;
        }

    private:
        mutable Ptr impl_;
    };

}

#endif //SMART_PIMPL_BASE_HPP
