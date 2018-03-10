//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "test.h"

void test_default_construct_cp()
{
   Test t1;

   assert(t1.get_n() == 0);

   Test t2 = t1;

   assert(t1.get_n() == 0);
   assert(t2.get_n() == 0);
}

void test_nodefault_construct_cp()
{
   Test t1{1};

   assert(t1.get_n() == 1);

   Test t2 = t1;

   assert(t1.get_n() == 1);
   assert(t2.get_n() == 1);
}

int main()
{
    test_default_construct_cp();
    test_nodefault_construct_cp();

   return EXIT_SUCCESS;
}
