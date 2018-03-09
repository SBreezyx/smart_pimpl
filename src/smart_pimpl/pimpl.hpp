//
// pimpl.hpp
// Created by simon on 6/03/18.
//

#ifndef SMART_PIMPL_PIMPL_HPP
#define SMART_PIMPL_PIMPL_HPP

#include <memory>
#include <value_ptr/value_ptr.hpp>

#include "smart_pimpl/internal/helpers.hpp"

namespace smart_pimpl {

    template<typename Interface>
    struct pimpl {
        struct Impl;

        /* Forward declarations of main classes */
        template<typename /* Policy*/>
        class Base;

        using EntityPtr = std::unique_ptr<Impl, Deleter<Impl>>;
        using ReferencePtr = std::shared_ptr<Impl>;
        using ValuePtr = value_ptr::value_ptr<Impl, Deleter<Impl>, Copier<Impl>>;

        /* Convenience typedefs for users. Add more as needed. */
        using Entity    = Base<EntityPtr>;

        using Reference = Base<ReferencePtr>;

        using Value     = Base<value_ptr>;
    };
}

#include "smart_pimpl/internal/base.hpp"

#endif // SMART_PIMPL_PIMPL_HPP
