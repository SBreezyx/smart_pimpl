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
    Value(int q1, int q2, const std::string &s);

    int get_q1();
    int get_q2();
    std::string get_s();

    auto mult() -> int;
};


#endif //SMART_PIMPL_VALUE_H
