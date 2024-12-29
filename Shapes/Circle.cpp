#include "Circle.h"

   Circle::Circle(double radius)
   :_radius{radius}{};
   
   std::string Circle::name()
   {
      return "(Circle) of radius " + std::to_string(_radius);
   }
   
   double Circle::area()
   {
      return (M_PI * (pow(_radius,2)));
   }