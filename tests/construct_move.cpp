//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "test.h"

void test_default_construct_mv()
{
   Test t1;

   assert(t1.get_n() == 0);

   Test t2 = std::move(t1);

   assert(t2.get_n() == 0);
}

void test_nodefault_construct_mv()
{
   Test t1{1};

   assert(t1.get_n() == 1);

   Test t2 = std::move(t1);

   assert(t2.get_n() == 1);
}

int main()
{
    test_default_construct_mv();
    test_nodefault_construct_mv();

   return EXIT_SUCCESS;
}
