//
// reference.h
// Created by simon on 9/03/18.
//

#ifndef SMART_PIMPL_REFERENCE_H
#define SMART_PIMPL_REFERENCE_H

#include <smart_pimpl/pimpl.hpp>

class Reference : public smart_pimpl::pimpl<Reference>::Reference {
public:
    Reference() = default;

    Reference(int n);

};


#endif // SMART_PIMPL_REFERENCE_H
