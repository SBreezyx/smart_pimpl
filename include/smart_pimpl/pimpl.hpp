//
// pimpl.hpp
// Created by simon on 6/03/18.
//

#ifndef PRACTICE_PIMPL_HPP
#define PRACTICE_PIMPL_HPP

#include "internal/impl_ptr.hpp"

namespace smart_pimpl {
   template<typename>
   struct pimpl {
      struct Impl;

      template<typename Ptr>
      class Base {
      public:
         // something

      protected:
         template<typename ...Args>
         explicit Base(Args &&...args) : impl_{ make_ptr<Ptr>(args...) } {}

         Ptr impl_;
      };

      /* Convenience typedefs for users. Add more as needed. */
      using Entity  = Base<std::unique_ptr<Impl, Deleter<Impl>>>;
      using Pointer = Base<std::shared_ptr<Impl>>;
      using Value   = Base<impl_ptr<Impl>>;
   };
}
#endif // PRACTICE_PIMPL_HPP
