//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "test.h"

#ifdef e
#define def_base SmartPimpl::Base<DefTest, SmartPimpl::Entity>
#endif

#ifdef r
#define def_base SmartPimpl::Base<DefTest, SmartPimpl::Reference>
#endif

class DefTest;

template <>
struct def_base::Impl {
    int n = 0;
};

class DefTest : def_base {
public:
    DefTest(int a, int b) :
        Base()
    {
    }

    auto get_n() -> int
    {
        return impl()->n;
    }
};

void test_default()
{
    Test t;

    assert(t.get_n() == 0);
}

void test_default_dummy()
{
    DefTest t{1, 2};

    assert(t.get_n() == 0);
}

int main()
{
    test_default();
    test_default_dummy();

    return EXIT_SUCCESS;
}
