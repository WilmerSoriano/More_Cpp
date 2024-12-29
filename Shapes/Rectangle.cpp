#include "Rectangle.h"

   Rectangle::Rectangle(double height, double width)
   :_height{height}, _width{width}{};

   
   std::string Rectangle::name()
   {
      return "|Rectangle|";
   }
   
   double Rectangle::area()
   {
      return (_height*_width);
   }