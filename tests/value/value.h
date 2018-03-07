//
// Created by simon on 7/03/18.
//

#ifndef SMART_PIMPL_VALUE_H
#define SMART_PIMPL_VALUE_H

#include <smart_pimpl/pimpl.hpp>

class Value : public smart_pimpl::pimpl<Value>::Value {
public:
   Value() = default;
};


#endif //SMART_PIMPL_VALUE_H
