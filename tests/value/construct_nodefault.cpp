//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "value.h"

void test_nodefault()
{
    Value v{ 1 };

    assert(v.get_n() == 1);
}

int main()
{
    test_nodefault();
    return EXIT_SUCCESS;
}
