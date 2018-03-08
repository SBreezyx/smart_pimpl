//
// Created by simon on 7/03/18.
//

#include "value.h"

template <>
struct smart_pimpl::pimpl<Value>::Impl {

};

Value::Value() :
   smart_pimpl::pimpl<Value>::Value()
{

}
