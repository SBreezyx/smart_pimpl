//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "test.h"

void test_self_assign_mv()
{
    Test t1;

    assert(t1.get_n() == 0);

    t1 = std::move(t1);    // self assignment should do nothing

    assert(t1.get_n() == 0);
}

void test_default_to_default_assign_mv()
{
    Test t1;
    Test t2;

    assert(t1.get_n() == 0);

    assert(t2.get_n() == 0);

    t2 = std::move(t1);

    assert(t2.get_n() == 0);

}

void test_default_to_nodefault_assign_mv()
{
    Test t1;
    Test t2{ 1 };

    assert(t1.get_n() == 0);

    assert(t2.get_n() == 1);

    t2 = std::move(t1);

    assert(t2.get_n() == 0);

}

void test_nodefault_to_default_assign_mv()
{
    Test t1;
    Test t2{ 1 };

    assert(t1.get_n() == 0);

    assert(t2.get_n() == 1);

    t1 = std::move(t2);

    assert(t1.get_n() == 1);

}

void test_nodefault_to_nodefault_assign_mv()
{
    Test t1{ 1 };
    Test t2{ 2 };

    assert(t1.get_n() == 1);

    assert(t2.get_n() == 2);

    t2 = std::move(t1);

    assert(t2.get_n() == 1);

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
