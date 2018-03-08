//
// Created by simon on 7/03/18.
//

#ifndef SMART_PIMPL_IMPL_PTR_HPP
#define SMART_PIMPL_IMPL_PTR_HPP

namespace smart_pimpl {

   template<typename Data>
   class impl_ptr {
   public:
      using pointer = Data*;
      using element_type = Data;
      using deleter_type = Deleter<Data>;
      using copy_type = Copier<Data>;

      explicit impl_ptr(Data *d, deleter_type dummy = nullptr);

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
      element_type *data_;
      const deleter_type del_ = default_delete<Data>;
      const copy_type cp_ =  default_copy<Data>;
   };

}

#include "impl_ptr.inl"

#endif //SMART_PIMPL_IMPL_PTR_HPP
