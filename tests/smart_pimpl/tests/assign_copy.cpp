//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "../entity/Entity.h"
#include "../reference/reference.h"
#include "../value/value.h"

void test_self_assign_mv()
{
    Value v1;

    assert(v1.get_n() == 0);

    v1 = v1;    // self assignment should do nothing

    assert(v1.get_n() == 0);
}

void test_default_to_default_assign_cp()
{
    Value v1;
    Value v2;

    assert(v1.get_n() == 0);

    assert(v2.get_n() == 0);

    v2 = v1;

    assert(v1.get_n() == 0);

    assert(v2.get_n() == 0);

}

void test_default_to_nodefault_assign_cp()
{
    Value v1;
    Value v2{ 1 };

    assert(v1.get_n() == 0);

    assert(v2.get_n() == 1);

    v2 = v1;

    assert(v1.get_n() == 0);

    assert(v2.get_n() == 0);

}

void test_nodefault_to_default_assign_cp()
{
    Value v1;
    Value v2{ 1 };

    assert(v1.get_n() == 0);

    assert(v2.get_n() == 1);

    v1 = v2;

    assert(v1.get_n() == 1);

    assert(v2.get_n() == 1);

}

void test_nodefault_to_nodefault_assign_cp()
{
    Value v1{ 1 };
    Value v2{ 2 };

    assert(v1.get_n() == 1);

    assert(v2.get_n() == 2);

    v2 = v1;

    assert(v1.get_n() == 1);

    assert(v2.get_n() == 1);

}

int main()
{
    test_self_assign_mv();
    test_default_to_default_assign_cp();
    test_default_to_nodefault_assign_cp();
    test_nodefault_to_default_assign_cp();
    test_nodefault_to_nodefault_assign_cp();

    return EXIT_SUCCESS;
}
