//
// default_copy.hpp
// Created by simon on 8/03/18.
//

#ifndef SMART_PIMPL_DEFAULT_COPY_HPP
#define SMART_PIMPL_DEFAULT_COPY_HPP

namespace value_ptr {
    /*
     * This class is supposed to represent a default copy operation.
     * This means it invokes the copy assigner of whatever it gets passed in operator()
     */
    template <typename T>
    struct default_copy {
        constexpr default_copy() noexcept = default;

        template <typename U>
        requires std::is_convertible_v<U*, T*>
        default_copy(const default_copy<U> &) noexcept {}

        T *operator()(T* to, const T* from) const
        {
            *to = *from;
            return to;
        }
    };
}

#endif // SMART_PIMPL_DEFAULT_COPY_HPP
