//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "../entity/Entity.h"
#include "../reference/reference.h"
#include "../value/value.h"

void test_default_construct_mv()
{
   Value v1;

   assert(v1.get_n() == 0);

   Value v2 = std::move(v1);

   assert(v2.get_n() == 0);
}

void test_nodefault_construct_mv()
{
   Value v1{1};

   assert(v1.get_n() == 1);

   Value v2 = std::move(v1);

   assert(v2.get_n() == 1);
}

int main()
{
    test_default_construct_mv();
    test_nodefault_construct_mv();

   return EXIT_SUCCESS;
}
