//
// pimpl.hpp
// Created by simon on 6/03/18.
//

#ifndef SMART_PIMPL_PIMPL_HPP
#define SMART_PIMPL_PIMPL_HPP

#include <memory>

#include "internal/helpers.hpp"
#include "internal/impl_ptr.hpp"

namespace smart_pimpl {

   template<typename>
   struct pimpl {
      struct Impl;

      /* Forward declarations of main classes */
      template<template <typename> typename /* Policy*/> class Base;

      /* Convenience typedefs for users. Add more as needed. */
      using Entity  = Base<std::unique_ptr>;
      using Pointer = Base<std::shared_ptr>;
      using Value   = Base<impl_ptr>;
   };
}

#include "internal/base.hpp"

#endif // SMART_PIMPL_PIMPL_HPP
