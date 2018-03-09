//
// Created by simon on 7/03/18.
//

#ifndef SMART_PIMPL_VALUE_H
#define SMART_PIMPL_VALUE_H

#include <string>

#include <smart_pimpl/pimpl.hpp>

class Value : public smart_pimpl::pimpl<Value>::Value {
public:
    Value() = default;

    explicit Value(int n);

    auto get_n() -> int;

    auto set_n(int m) -> void;

    auto mult(int m) -> int;
};


#endif //SMART_PIMPL_VALUE_H
