//
// Created by simon on 7/03/18.
//

#ifndef SMART_PIMPL_IMPL_PTR_INL
#define SMART_PIMPL_IMPL_PTR_INL

namespace smart_pimpl {
   template<typename Data>
   inline impl_ptr<Data>::impl_ptr(Data *d, Deleter<Data>) :
         data_{ d }
   {}

   template<typename Data>
   impl_ptr<Data>::~impl_ptr()
   {
      del_(data_);
   }

   template<typename Data>
   impl_ptr<Data>::impl_ptr(const impl_ptr &other) :
         data_{ other.cp_(other.data_) }
   {
   }

   template<typename Data>
   impl_ptr<Data>::impl_ptr(impl_ptr &&other) noexcept :
         data_{ other.data_ }
   {
      other.data_ = nullptr;
   }

   template<typename Data>
   impl_ptr <Data> &impl_ptr<Data>::operator=(const impl_ptr &other)
   {
      if (this != &other) {
         data_ = other.cp_(other.data_);
      }

      return *this;
   }

   template<typename Data>
   impl_ptr <Data> &impl_ptr<Data>::operator=(impl_ptr &&other) noexcept
   {
      if (this != &other) {
         data_ = other.data_;
         other.data_ = nullptr;
      }

      return *this;
   }

   template<typename Data>
   inline Data *impl_ptr<Data>::operator->()
   {
      return data_;
   }

   template<typename Data>
   inline const Data *impl_ptr<Data>::operator->() const
   {
      return *data_;
   }

   template<typename Data>
   inline Data &impl_ptr<Data>::operator*()
   {
      return data_;
   }

   template<typename Data>
   inline const Data &impl_ptr<Data>::operator*() const
   {
      return *data_;
   }

   template<typename Impl, typename ...Args>
   impl_ptr <Impl> make_impl(Args &&...args)
   {
      return new Impl(std::forward<Args>(args)...);
   }
}
#endif //SMART_PIMPL_IMPL_PTR_INL
