/*
   This code implements an object-oriented program in
   C++ that demonstrates polymorphism, inheritance, and 
   abstract classes. The program basic objective
   is to abstract the shape class and derive them into 2 class 
   Rectangle and Circle and print the describtion of the shape
   and their areas.

   NOTE: Use the makefile to compile
   and run under [./Shapes]
*/


#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include <vector>

int main()
{
   std::vector<Shape*>shapes;

   shapes.push_back(new Rectangle(3.0, 4.0));
   shapes.push_back(new Circle(2.0));
   
   for(Shape* obj: shapes)
      std::cout << obj ->to_string()<< std::endl;
   return 0;
}