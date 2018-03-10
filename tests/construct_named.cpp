//
// construct_named.cpp
// Created by simon on 10/03/18.
//

#include <cstdlib>
#include <cassert>

#include "test.h"

int main() {
    Test t = Test::make_squared(5);

    assert(t.get_n() == 25);

    return EXIT_SUCCESS;
}