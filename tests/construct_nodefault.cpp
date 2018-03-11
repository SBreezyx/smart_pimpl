//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "test.h"

#ifdef e
#define nodef_base SmartPimpl::Entity<NoDefTest>
#endif

#ifdef r
#define nodef_base SmartPimpl::Reference<NoDefTest>
#endif


class NoDefTest;

template<>
struct nodef_base::Impl {
    Impl(int data) :
        my_data{ data }
    {
    }

    int my_data;
};

class NoDefTest : nodef_base {
public:
    explicit NoDefTest(int data) : Base(data)
    {
    }

    auto get_my_data() -> int
    {
        return impl()->my_data;
    }
};

void test_nodefault()
{
    Test t{ 1 };

    assert(t.get_n() == 1);
}

void test_nodefault_get()
{
    NoDefTest nt{ 15 };

    assert(nt.get_my_data() == 15);
}

int main()
{
    test_nodefault();

    test_nodefault_get();
    return EXIT_SUCCESS;
}
