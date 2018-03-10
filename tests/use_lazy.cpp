//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "test.h"

int main()
{
    Test t1;
    t1.set_n(23);

    assert(t1.mult(2) == 46);

    return EXIT_SUCCESS;
}
