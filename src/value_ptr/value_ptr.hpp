//
// Created by simon on 7/03/18.
//

#ifndef SMART_PIMPL_IMPL_PTR_HPP
#define SMART_PIMPL_IMPL_PTR_HPP

#include <concepts.hpp>

#include "internal/default_copy.hpp"
#include "internal/default_delete.hpp"

#include "internal/value_ptr_ops.inl"

namespace value_ptr {
    template<typename T, Callable<T *> Deleter = default_delete<T>, Callable<T* , const T*> Copier = default_copy<T>>
    class value_ptr {
    public:
        using pointer = T *;
        using reference = T &;
        using element_type = T;
        using deleter_type = Deleter;
        using copier_type = Copier;

        value_ptr(pointer data, deleter_type del, copier_type cp) :
            del_{ std::forward<deleter_type>(del) },
            cp_{ std::forward<copier_type>(cp) },
            data_{ data }
        {}

        explicit value_ptr(pointer data) :
            value_ptr(deleter_type(), copier_type(), data)
        {}

        constexpr value_ptr() noexcept = default;

        constexpr value_ptr(nullptr_t) noexcept :
            value_ptr()
        {}

        ~value_ptr()
        {
            auto &ptr = get();

            if (ptr) {
                get_deleter()(ptr);
            }

            ptr = nullptr;
        }

        template<typename U, typename D, typename C>
        requires SafeConvertible<value_ptr<U, D, C>, value_ptr>
        value_ptr(const value_ptr<U, D, C> &other) :
            value_ptr(std::forward<deleter_type >(other.get_deleter()),
                      std::forward<copier_type >(other.get_copier()),
                      get_copier()(get(), other.get()))
        {}

        value_ptr(const value_ptr &other) :
            value_ptr(std::forward<deleter_type >(other.get_deleter()),
                      std::forward<copier_type >(other.get_copier()),
                      other.get_copier()(get(), other.get()))
        {}

        template<typename U, typename D, typename C>
        requires SafeConvertible<value_ptr<U, D, C>, value_ptr>
        value_ptr(value_ptr<U, D, C> &&other) noexcept :
            value_ptr(std::forward<D>(other.get_deleter()),
                      std::forward<C>(other.get_copier()),
                      other.release())
        {}

        value_ptr(value_ptr &&other) noexcept :
            value_ptr(std::forward<deleter_type>(other.get_deleter()),
                      std::forward<copier_type>(other.get_copier()),
                      other.release())
        {}

        template<typename U, typename D, typename C>
        requires SafeConvertible<value_ptr<U, D, C>, value_ptr>
        auto operator=(const value_ptr<U, D, C> &other) -> value_ptr &
        {
            other.get_copier()(other.get(), get());
            get_deleter() = std::forward<D>(other.get_deleter());
            get_copier() = std::forward<C>(other.get_copier());
        }

        auto operator=(const value_ptr &other) -> value_ptr &
        {
            other.get_copier()(other.get(), get());
            get_deleter() = std::forward<deleter_type>(other.get_deleter());
            get_copier() = std::forward<copier_type>(other.get_copier());
        }

        template<typename U, typename D, typename C>
        requires SafeConvertible<value_ptr<U, D, C>, value_ptr>
        auto operator=(value_ptr<U, D, C> &&other) noexcept -> value_ptr &
        {
            if (this != &other) {
                reset(other.release());
                get_deleter() = std::forward<D>(other.get_deleter());
                get_copier() = std::forward<C>(other.get_copier());
            }

            return *this;
        }

        auto operator=(value_ptr &&other) noexcept -> value_ptr &
        {
            if (this != &other) {
                reset(other.release());
                get_deleter() = std::forward<deleter_type>(other.get_deleter());
                get_copier() = std::forward<copier_type>(other.get_copier());
            }

            return *this;
        }

        auto get() noexcept -> std::add_lvalue_reference_t<pointer>
        {
            return data_;
        }

        auto get_deleter() noexcept -> std::add_lvalue_reference_t<deleter_type>
        {
            return del_;
        }

        auto get_copier() noexcept -> std::add_lvalue_reference_t<copier_type>
        {
            return cp_;
        }

        auto get() const noexcept -> std::add_lvalue_reference_t<const pointer>
        {
            return data_;
        }

        auto get_deleter() const noexcept -> std::add_lvalue_reference_t<const deleter_type>
        {
            return del_;
        }

        auto get_copier() const noexcept -> std::add_lvalue_reference_t<const copier_type>
        {
            return cp_;
        }

        auto release() noexcept -> pointer
        {
            pointer old = get();
            reset();
            return old;
        }

        auto reset(pointer p = pointer()) noexcept -> void
        {
            pointer old = get();
            get() = p;
            get_deleter()(old);
        }

        auto swap(value_ptr &other) noexcept -> void
        {
            std::swap(get(), other.get());
            std::swap(get_deleter(), other.get_deleter());
            std::swap(get_copier(), other.get_copier());
        }

        auto operator->() noexcept -> pointer
        {
            return get();
        }

        auto operator*() -> reference
        {
            return *get();
        }

        auto operator->() const noexcept -> const pointer
        {
            return get();
        }

        auto operator*() const -> const reference
        {
            return *get();
        }

        explicit operator bool() const noexcept
        {
            return get() != pointer();
        }

        friend auto operator==<>(const value_ptr<T> &lhs, const value_ptr<T> &rhs) -> bool;
        friend auto operator!=<>(const value_ptr<T> &lhs, const value_ptr<T> &rhs) -> bool;

        friend auto operator==<>(nullptr_t ptr, const value_ptr<T> &rhs) noexcept -> bool;
        friend auto operator!=<>(nullptr_t ptr, const value_ptr<T> &rhs) noexcept -> bool;

        friend auto operator==<>(const value_ptr<T> &lhs, nullptr_t ptr) noexcept -> bool;
        friend auto operator!=<>(const value_ptr<T> &lhs, nullptr_t ptr) noexcept -> bool;

    private:
        deleter_type del_;
        copier_type cp_;

        element_type *data_;
    };

    template<typename T, typename ...Args>
    auto make_value(Args&& ...args) -> value_ptr<T>
    {
        return value_ptr<T>(new T(std::forward<Args>(args)...));
    }
}

#endif //SMART_PIMPL_IMPL_PTR_HPP
