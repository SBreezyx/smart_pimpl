//
// value_ptr_ops.inl
// Created by simon on 8/03/18.
//

#ifndef SMART_PIMPL_VALUE_PTR_OPS_INL
#define SMART_PIMPL_VALUE_PTR_OPS_INL

#include <stddef.h>

namespace value_ptr {
    /* Forward Declarations for operators */
    template<typename Data, Callable<Data *> Deleter, Callable<Data* , const Data*> Copier>
    class value_ptr;

    template<typename Data, typename Deleter, typename Copier>
    auto operator==(const value_ptr<Data, Deleter, Copier> &lhs, const value_ptr<Data, Deleter, Copier> &rhs) -> bool
    {
        return lhs.data_ == rhs.data_;  // reference semantics
    }

    template<typename Data, typename Deleter, typename Copier>
    auto operator!=(const value_ptr<Data, Deleter, Copier> &lhs, const value_ptr<Data, Deleter, Copier> &rhs) -> bool
    {
        return !(lhs == rhs);
    }

    template<typename Data, typename Deleter, typename Copier>
    auto operator==(nullptr_t, const value_ptr<Data, Deleter, Copier> &rhs) noexcept -> bool
    {
        return rhs.data_ == nullptr;  // reference semantics
    }

    template<typename Data, typename Deleter, typename Copier>
    auto operator!=(nullptr_t, const value_ptr<Data, Deleter, Copier> &rhs) noexcept -> bool
    {
        return rhs.data_ != nullptr;
    }

    template<typename Data, typename Deleter, typename Copier>
    auto operator==(const value_ptr<Data, Deleter, Copier> &lhs, nullptr_t) noexcept -> bool
    {
        return lhs.data_ == nullptr;  // reference semantics
    }

    template<typename Data, typename Deleter, typename Copier>
    auto operator!=(const value_ptr<Data, Deleter, Copier> &lhs, nullptr_t) noexcept -> bool
    {
        return lhs.data_ != nullptr;
    }
}

#endif // SMART_PIMPL_VALUE_PTR_OPS_INL
