#include "Shape.h"

#ifndef __CIRCLE_H
#define __CIRCLE_H

class Circle: public Shape
{
   public:
   Circle(double radius);
   
   std::string name()override;
   
   double area()override;
   
   private:
   double _radius;
};
#endif