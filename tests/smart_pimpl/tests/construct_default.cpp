//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>
#include <iostream>

#include "../entity/Entity.h"
#include "../reference/reference.h"
#include "../value/value.h"

template<typename T>
void test_default()
{
    T t;

    assert(t.get_n() == 0);
}

int main()
{
    int op;
    std::cin >> op;

    switch (op) {
        case 1:
            test_default<Entity>();
            break;

        case 2:
            test_default<Reference>();
            break;

        case 3:
            test_default<Value>();
    }


    return EXIT_SUCCESS;
}
