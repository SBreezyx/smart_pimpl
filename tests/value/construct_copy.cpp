//
// Created by simon on 7/03/18.
//

#include <cstdlib>

#include "value.h"

int main() {
   Value v1{0, 1, "Boo"};

   Value v2 = v1;
   (void) v2;
   
   return EXIT_SUCCESS;
}
