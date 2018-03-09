//
// concepts.hpp
// Created by simon on 9/03/18.
//

#ifndef SMART_PIMPL_CONCEPTS_HPP
#define SMART_PIMPL_CONCEPTS_HPP

#include <type_traits>

namespace value_ptr {
    template <typename T, typename ...Args>
    concept bool Callable = std::is_invocable_v<T, Args...>;

    template <typename From, typename To>
    concept bool SafeConvertible = requires
    {
        typename From::pointer;
        typename From::deleter_type;
        typename From::copier_type;

        typename To::pointer;
        typename To::deleter_type;
        typename To::copier_type;

        std::is_convertible_v<typename From::pointer, typename To::pointer>;
        std::is_convertible_v<typename From::deleter_type, typename To::deleter_type>;
        std::is_convertible_v<typename From::copier_type, typename To::copier_type>;
        !std::is_array_v<typename From::pointer>;
    };
}


#endif // SMART_PIMPL_CONCEPTS_HPP
