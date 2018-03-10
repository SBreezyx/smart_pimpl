//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "test.h"

int main() {
   Test t1{5};

   assert(t1.mult(5) == 25);

   return EXIT_SUCCESS;
}
