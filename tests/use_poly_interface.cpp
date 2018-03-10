//
// use_poly_interface.cpp
// Created by simon on 10/03/18.
//

#include <cstdlib>
#include <cassert>
#include <iostream>

#include "test.h"

class MyTest : public Test {
public:
    explicit MyTest(int n) :
        Test(n)
    {}

    void speak() override
    {
        std::cout << "i am my test" << std::endl;
    }
};

int main() {
    Test t{1};
    MyTest m{5};

    Test *tp = &t;
    assert(tp->get_n() == 1);

    tp = &m;
    assert(tp->get_n() == 5);

    return EXIT_SUCCESS;
}