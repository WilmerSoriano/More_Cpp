#include "Shape.h"

#ifndef __RECTANGLE_H
#define __RECTANGLE_H

class Rectangle : public Shape
{
  public:
   Rectangle(double height, double width);
   
   std::string name()override;
   
   double area()override;
   
   private:
   double _height;
   double _width;
};
#endif