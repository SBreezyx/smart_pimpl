//
// Created by simon on 7/03/18.
//

#include "value.h"

using Base = smart_pimpl::pimpl<Value>;

template<>
struct Base::Impl {
    explicit Impl(int n = 0) :
        n_{ n }
    {}

    int n_;
};


Value::Value(int n) :
    Base(n)
{
}

auto Value::mult(int m) -> int
{
    return impl()->n_ * m;
}

auto Value::get_n() -> int
{
    return impl()->n_;
}

auto Value::set_n(int m) -> void
{
    impl()->n_ = m;
}

