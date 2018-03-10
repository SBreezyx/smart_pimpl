//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "test.h"

void test_default()
{
    Test t;

    assert(t.get_n() == 0);
}

int main()
{
    test_default();

    return EXIT_SUCCESS;
}
