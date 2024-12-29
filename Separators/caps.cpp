/* 
   This code creates 2 vectors to each hold Caps and lowerCase 
   & seprates them in a list. This code will demostrate my ability
   to work with vectors and understanding of how the compiler order 
   the letter in a Stack or Heap.
   
   Suggestion: A Makefile is created but not necessary
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

bool Bylength(std::string first, std::string last) //This function return true if...
{
   if(first.length() == last.length())// if the lenght are he same ..
   {
      return first < last;  //then one string must be greater(true) or the same for false
   }
   else
   {
         return first.length() < last.length();  //otherwise it's not the same so compare by length
   }
}

int main(int args, char* argv[])
{
   int a{1};
   std::string m1;
   std::string m2;
   std::vector<std::string> obj1; /*stack only Capitalized*/ 
   std::vector<std::string>* obj2  = new std::vector<std::string>; /*heap only lowercase*/
   
   while( a < args)
   {
      m1 = argv[a];//capitilize this char
      m2 = argv[a];//compare the first char 
      
      if(toupper(m1[0]) == m2[0])
      {
         obj1.push_back(argv[a]);
      }
      else
      {
         obj2->push_back(argv[a]);
      }
      a++;
   }
   
   std::sort(obj1.begin(),obj1.end()); //sort by default operators ASCII?
   
   std::sort(obj2->begin(), obj2->end(), Bylength);  /*The last parameter allowes me to insert a function..
                                                      and create a sort of my desire*/   
   
   std::cout <<"Capitalized:"<<std::endl;
   for(auto i : obj1) std::cout << i <<std::endl;

   std::cout << " " << std::endl; //Separator

   std::cout<<"Lower Case:"<<std::endl;
   for(auto j : *obj2) std::cout << j << std::endl;

   return 0;
}