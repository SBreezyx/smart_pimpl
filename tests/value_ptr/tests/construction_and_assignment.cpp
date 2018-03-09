//
// construction_and_assignment.cpp
// Created by simon on 8/03/18.
//

#include <cstdlib>

#include <value_ptr/value_ptr.hpp>
#include <iostream>

template <typename T>
using vptr = value_ptr::value_ptr<T>;

int main() {

    vptr<int> v = value_ptr::make_value<int>(2);

    vptr<float> v2 = v;

    std::cout << *v << std::endl;

    return EXIT_SUCCESS;
}