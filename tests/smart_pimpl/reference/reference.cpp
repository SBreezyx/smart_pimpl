//
// reference.cpp
// Created by simon on 9/03/18.
//

#include "reference.h"

template <>
struct smart_pimpl::pimpl<Reference>::Impl {
    Impl(int N = 30) :
        n{N}
    {}

    int n;
};

Reference::Reference(int n) :
    smart_pimpl::pimpl<Reference>::Reference(n)
{
}
