//
// Created by simon on 7/03/18.
//

#ifndef SMART_PIMPL_PIMPL_PTR_HPP
#define SMART_PIMPL_PIMPL_PTR_HPP

#include <memory>
#include <utility>

#include "helpers.hpp"

namespace smart_pimpl {
   template<typename Data>
   class impl_ptr {
   public:
      explicit impl_ptr(Data *d, Deleter<Data> dummy = nullptr);

      ~impl_ptr();

      impl_ptr(const impl_ptr &other);

      impl_ptr(impl_ptr &&other) noexcept;

      impl_ptr &operator=(const impl_ptr &other);

      impl_ptr &operator=(impl_ptr &&other) noexcept;

      Data *operator->();

      const Data *operator->() const;

      Data &operator*();

      const Data &operator*() const;

   private:
      Data *data_;
      const Deleter<Data> del_ = default_delete;
      const Copier<Data> cp_ = default_copy;
   };

   template<template<typename T> typename Ptr, typename ...Args>
   Ptr make_ptr(Args&& ...args)
   {
      return Ptr(new T(std::forward<Args>(args)...), default_delete<T>);
   }

}

#include "impl_ptr.inl"

#endif //SMART_PIMPL_PIMPL_PTR_HPP
