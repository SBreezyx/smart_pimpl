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

        Base() = default;

        template<typename ...Args>
        explicit Base(Args &&...args) : impl_{ make_ptr < Policy < Impl >> (args...) }
        {}

        Policy<Impl> impl() const
        {
            return impl_;
        }

    private:
        mutable Policy <Impl> impl_;
    };

}

#endif //SMART_PIMPL_BASE_HPP
