//
// Created by simon on 7/03/18.
//

#include <cstdlib>
#include <cassert>

#include "value.h"

int main() {
   Value v1{5};

   assert(v1.mult(5) == 25);

   return EXIT_SUCCESS;
}
