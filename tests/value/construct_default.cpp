//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "value.h"

void test_default()
{
    Value v;

    assert(v.get_n() == 0);
}

int main()
{
    test_default();
    return EXIT_SUCCESS;
}
