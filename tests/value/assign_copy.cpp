//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "value.h"

int main()
{
    Value v1;
    Value v2{1,2, "3"};
    Value v3;

    assert(v1.get_q1() == 0);
    assert(v1.get_q2() == 0);
    assert(std::empty(v1.get_s()));
    v1 = v1;    // self assignment should do nothing
    assert(v1.get_q1() == 0);
    assert(v1.get_q2() == 0);
    assert(std::empty(v1.get_s()));

    v3 = v1;    // make sure nothing screwy happens when default construct copies
    assert(v1.get_q1() == 0);
    assert(v1.get_q2() == 0);
    assert(std::empty(v1.get_s()));

    assert(v3.get_q1() == 0);
    assert(v3.get_q2() == 0);
    assert(std::empty(v3.get_s()));

    v1 = v2;    // can copy data over

    v1 = v3;    // and removal of data also should be ok

    return EXIT_SUCCESS;
}
