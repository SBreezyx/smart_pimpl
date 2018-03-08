//
// Created by simon on 7/03/18.
//

#ifndef SMART_PIMPL_IMPL_PTR_HPP
#define SMART_PIMPL_IMPL_PTR_HPP

namespace smart_pimpl {
    /* Forward Declarations for operators */
    template <typename Data> class impl_ptr;

    template<typename Data> bool operator== (const impl_ptr<Data> &lhs, const impl_ptr<Data> &rhs);
    template<typename Data> bool operator!= (const impl_ptr<Data> &lhs, const impl_ptr<Data> &rhs);

    template<typename Data> bool operator== (nullptr_t ptr, const impl_ptr<Data> &rhs) noexcept;
    template<typename Data> bool operator!= (nullptr_t ptr, const impl_ptr<Data> &rhs) noexcept;

    template<typename Data> bool operator== (const impl_ptr<Data> &lhs, nullptr_t ptr) noexcept;
    template<typename Data> bool operator!= (const impl_ptr<Data> &lhs, nullptr_t ptr) noexcept;

    template<typename Data>
    class impl_ptr {
    public:
        using pointer = Data *;
        using element_type = Data;
        using deleter_type = Deleter<Data>;
        using copy_type = Copier<Data>;

        explicit impl_ptr(Data *data, deleter_type del = default_delete<Data>, copy_type cp = default_copy<Data>);
        constexpr impl_ptr() noexcept;
        constexpr impl_ptr(nullptr_t) noexcept;

        ~impl_ptr();

        impl_ptr(const impl_ptr &other);

        impl_ptr(impl_ptr &&other) noexcept;

        impl_ptr &operator=(const impl_ptr &other);

        impl_ptr &operator=(impl_ptr &&other) noexcept;

              Data *operator->();
        const Data *operator->() const;

              Data &operator*();
        const Data &operator*() const;

        operator bool();    // NOLINT

        friend bool operator== <> (const impl_ptr<Data> &lhs, const impl_ptr<Data> &rhs);
        friend bool operator!= <> (const impl_ptr<Data> &lhs, const impl_ptr<Data> &rhs);

        friend bool operator== <> (nullptr_t ptr, const impl_ptr<Data> &rhs) noexcept;
        friend bool operator!= <> (nullptr_t ptr, const impl_ptr<Data> &rhs) noexcept;

        friend bool operator== <> (const impl_ptr<Data> &lhs, nullptr_t ptr) noexcept;
        friend bool operator!= <> (const impl_ptr<Data> &lhs, nullptr_t ptr) noexcept;

    private:
        element_type *data_;
        deleter_type del_;
        copy_type cp_;
    };
}

#include "impl_ptr.inl"

#endif //SMART_PIMPL_IMPL_PTR_HPP
