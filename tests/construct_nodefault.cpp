//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "test.h"

void test_nodefault()
{
    Test t{ 1 };

    assert(t.get_n() == 1);
}

int main()
{
    test_nodefault();
    return EXIT_SUCCESS;
}
