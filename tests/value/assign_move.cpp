//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "value.h"

void test_self_assign_mv()
{
    Value v1;

    assert(v1.get_n() == 0);

    v1 = std::move(v1);    // self assignment should do nothing

    assert(v1.get_n() == 0);
}

void test_default_to_default_assign_mv()
{
    Value v1;
    Value v2;

    assert(v1.get_n() == 0);

    assert(v2.get_n() == 0);

    v2 = std::move(v1);

    assert(v2.get_n() == 0);

}

void test_default_to_nodefault_assign_mv()
{
    Value v1;
    Value v2{ 1 };

    assert(v1.get_n() == 0);

    assert(v2.get_n() == 1);

    v2 = std::move(v1);

    assert(v2.get_n() == 0);

}

void test_nodefault_to_default_assign_mv()
{
    Value v1;
    Value v2{ 1 };

    assert(v1.get_n() == 0);

    assert(v2.get_n() == 1);

    v1 = std::move(v2);

    assert(v1.get_n() == 1);

}

void test_nodefault_to_nodefault_assign_mv()
{
    Value v1{ 1 };
    Value v2{ 2 };

    assert(v1.get_n() == 1);

    assert(v2.get_n() == 2);

    v2 = std::move(v1);

    assert(v2.get_n() == 1);

}

int main()
{
    test_self_assign_mv();
    test_default_to_default_assign_mv();
    test_default_to_nodefault_assign_mv();
    test_nodefault_to_default_assign_mv();
    test_nodefault_to_nodefault_assign_mv();

    return EXIT_SUCCESS;
}
