//
// Created by simon on 7/03/18.
//

#include "value.h"

using Base = smart_pimpl::pimpl<Value>;

template<>
struct Base::Impl {
   Impl(int q1, int q2, const std::string &s) :
         q1_{ q1 },
         q2_{ q2 },
         s_{ s }
   {}

   int q1_ = 0;
   int q2_ = 0;
   std::string s_ = "";
};


Value::Value(int q1, int q2, const std::string &s) :
   Base(q1, q2, s)
{
}

auto Value::mult() -> int
{
   return impl()->q1_ * impl()->q2_;
}

int Value::get_q1()
{
    return impl()->q1_;
}

int Value::get_q2()
{
    return impl()->q2_;
}

std::string Value::get_s()
{
    return impl()->s_;
}
