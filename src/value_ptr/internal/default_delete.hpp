//
// default_delete.hpp
// Created by simon on 8/03/18.
//

#ifndef SMART_PIMPL_DEFAULT_DELETE_HPP
#define SMART_PIMPL_DEFAULT_DELETE_HPP

#include <memory>

namespace value_ptr {
    template <typename T>
    using default_delete = std::default_delete<T>;
}

#endif // SMART_PIMPL_DEFAULT_DELETE_HPP
