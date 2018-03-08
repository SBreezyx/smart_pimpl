//
// Created by simon on 7/03/18.
//

#ifndef SMART_PIMPL_HELPERS_HPP
#define SMART_PIMPL_HELPERS_HPP

#include <utility>

namespace smart_pimpl {
   template<typename Impl>
   void default_delete(Impl *pimpl)
   {
      static_assert(sizeof(Impl) > 0);  // NOLINT
      delete pimpl;   // NOLINT
   }

   template <typename Impl>
   Impl *default_copy(Impl *pimpl) {
      static_assert(sizeof(Impl) > 0); // NOLINT
      return new Impl(*pimpl);
   }

   template <typename Impl>
   using Deleter = void (*)(Impl *);

   template <typename Impl>
   using Copier  = Impl *(*)(Impl *);

   template<typename Ptr, typename ...Args>
   auto make_ptr(Args&& ...args)
   {
      return Ptr(new typename Ptr::element_type(std::forward<Args>(args)...), default_delete<typename Ptr::element_type>);
   }
}
#endif //SMART_PIMPL_HELPERS_HPP
