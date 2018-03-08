//
// Created by simon on 7/03/18.
//

#ifndef SMART_PIMPL_IMPL_PTR_INL
#define SMART_PIMPL_IMPL_PTR_INL

#include <cassert>

namespace smart_pimpl {
    template<typename Data>
    inline impl_ptr<Data>::impl_ptr(Data *data, Deleter <Data> d, Copier <Data> c) :
        data_{ data },
        del_{ d },
        cp_{ c }
    {
    }

    template<typename Data>
    constexpr impl_ptr<Data>::impl_ptr() noexcept :
    data_{ nullptr },
    del_{ nullptr },
    cp_{ nullptr }
    {
    }

    template <typename Data>
    constexpr impl_ptr<Data>::impl_ptr(nullptr_t) noexcept : impl_ptr()
    {
    }


    template<typename Data>
    impl_ptr<Data>::~impl_ptr()
    {
        del_(data_);
    }

    template<typename Data>
    impl_ptr<Data>::impl_ptr(const impl_ptr &other) :
        data_{ other.cp_(other.data_) },
        del_{ other.del_ },
        cp_{ other.cp_ }
    {
    }

    template<typename Data>
    impl_ptr<Data>::impl_ptr(impl_ptr &&other) noexcept :
        data_{ other.data_ },
        del_{ other.del_ },
        cp_{ other.cp_ }
    {
        other.data_ = nullptr;
        /* Probably dont want to eradicate the destroyer and copier ! */
    }

    template<typename Data>
    impl_ptr <Data> &impl_ptr<Data>::operator=(const impl_ptr &other)
    {
        if (this != &other) {
            data_ = other.cp_(other.data_);
            del_ = other.del_;
            cp_ = other.cp_;
        }

        return *this;
    }

    template<typename Data>
    impl_ptr <Data> &impl_ptr<Data>::operator=(impl_ptr &&other) noexcept
    {
        if (this != &other) {
            data_ = other.data_;
            del_ = other.del_;
            cp_ = other.cp_;

            other.data_ = nullptr;
            /* Probably dont want to eradicate the destroyer and copier ! */
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

    template<typename Data>
    impl_ptr<Data>::operator bool()
    {
        return data_ != nullptr;
    }

    template<typename Data>
    bool operator==(const impl_ptr <Data> &lhs, const impl_ptr <Data> &rhs)
    {
        return lhs.data_ == rhs.data_;  // reference semantics
    }

    template<typename Data>
    bool operator!=(const impl_ptr <Data> &lhs, const impl_ptr <Data> &rhs)
    {
        return !(lhs == rhs);
    }

    template<typename Data>
    bool operator==(nullptr_t, const impl_ptr <Data> &rhs) noexcept
    {
        return rhs.data_ == nullptr;  // reference semantics
    }

    template<typename Data>
    bool operator!=(nullptr_t, const impl_ptr <Data> &rhs) noexcept
    {
        return rhs.data_ != nullptr;
    }

    template<typename Data>
    bool operator==(const impl_ptr <Data> &lhs, nullptr_t) noexcept
    {
        return lhs.data_ == nullptr;  // reference semantics
    }

    template<typename Data>
    bool operator!=(const impl_ptr <Data> &lhs, nullptr_t) noexcept
    {
        return lhs.data_ != nullptr;
    }


    template<typename Impl, typename ...Args>
    impl_ptr <Impl> make_impl(Args &&...args)
    {
        return new Impl(std::forward<Args>(args)...);
    }
}
#endif //SMART_PIMPL_IMPL_PTR_INL
