//
// Created by simon on 7/03/18.
//

#ifndef SMART_PIMPL_HELPERS_HPP
#define SMART_PIMPL_HELPERS_HPP
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

   template <typename Data>
   using Deleter = void (*)(Data *);

   template <typename Data>
   using Copier  = Data *(*)(Data *);
}
#endif //SMART_PIMPL_HELPERS_HPP
