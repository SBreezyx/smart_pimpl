//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "value.h"

void test_default_construct_cp()
{
   Value v1;

   assert(v1.get_n() == 0);

   Value v2 = v1;

   assert(v1.get_n() == 0);
   assert(v2.get_n() == 0);
}

void test_nodefault_construct_cp()
{
   Value v1{1};

   assert(v1.get_n() == 1);

   Value v2 = v1;

   assert(v1.get_n() == 1);
   assert(v2.get_n() == 1);
}

int main()
{
    test_default_construct_cp();
    test_nodefault_construct_cp();

   return EXIT_SUCCESS;
}
