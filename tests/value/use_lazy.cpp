//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "value.h"

int main()
{
    Value v1;
    v1.set_n(23);

    assert(v1.mult(2) == 46);

    return EXIT_SUCCESS;
}
