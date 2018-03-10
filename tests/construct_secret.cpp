//
// construct_secret.cpp
// Created by simon on 10/03/18.
//

#include <cstdlib>
#include <cassert>

#include "test.h"

int main() {
    Test t1 = Test::make_squared(5);
    Test t2 = Test::make_secret(13);

    assert(t1.secret() != t2.secret());

    return EXIT_SUCCESS;
}