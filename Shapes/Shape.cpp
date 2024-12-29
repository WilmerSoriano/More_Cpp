#include "Shape.h"

   /*Note to self, only difference is no method and Shape.h*/
   
   std::string Shape::to_string()
   {
      return name() + " with area of " + std::to_string(area());
   }