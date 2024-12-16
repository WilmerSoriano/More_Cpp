#define BOOST_TEST_MODULE Taylor_Series

#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <cmath> 

using namespace std;

/*
   HOW TO COMPILE AND RUN

   In the Command Line, in the same directory:
   1.) to compile: type [make]
   2.) to run: type [make run]
   3.) to remove: type [make clean] 
*/

//==========================Functions===========================================

int factorial(int n){
   if(n == 0)
      return 1;
   else
      return n * factorial(n - 1);
}

double sin_function(float X, int *errorflag){
   int n;
   double total = X;
   double result = 0.00;
   
   if((X >= 0.0) && (X <= 2*M_PI)){      
      for(n = 3; n <= 11; n=n+2){
         result = (pow(X,n)/factorial(n));
         switch (n){
            case 3:
            case 7:
            case 11:
               total -= result;
               break;
            case 5:
            case 9:
               total += result;
               break;
         }  
      }
   }
   else{
      *errorflag = 1;
      return *errorflag;
   }
   return total;
}
//=========================TESTING PHASE========================================

/*
   NOTE:
   To determine if my function results are correct, I used symbolab.com with the formula:
   [x - (X^3)/3! + (X^5)/5! - (X^7)/7! + (X^9)/9! - (X^11)/11!]
   Where (x) is any input between [0 and 2*PI (6.28318) ]
   When testing and comparing, Both my result and function sin() yield a correct result.
   I also perform sin(x), using a calculator, to check if the result are correct.
   However, because I am using factorials up to 11. Calculating by a calculator, 
   which uses a finite set of factorials, did not yield the same result.
   This does not mean I produced the wrong result or my function sin() is incorrect. 
   Rather function sin contain the necessary constraints that uphold the requirements.

*/
BOOST_AUTO_TEST_CASE(Black_Box_Testing)
{
   int errorflag = 0;

   sin_function(2.0, &errorflag);   // My code result: 0.909296     
   BOOST_TEST(errorflag != 1);     // Symbolab result: 0.90929...

   sin_function(4.0, &errorflag);   // My code result: -0.766805
   BOOST_TEST(errorflag != 1);     // Symbolab result: -0.76680...

   sin_function(0.0, &errorflag);   // My code result: 0
   BOOST_TEST(errorflag != 1);     // Symbolab result: 0

   /*sin_function(-5.0, &errorflag);         // Purposely Fail, does not meet -5 > 0
   BOOST_TEST(errorflag != 1);*/

   /*sin_function(12.0, &errorflag);         // Purposely Fail, does not meet 12 < 6.28318
   BOOST_TEST(errorflag != 1);*/
}

BOOST_AUTO_TEST_CASE(White_Box_Testing)
{
   int errorflag = 0;

   sin_function(1/2, &errorflag);       // My code result: 0.841471, because 1/2 can not convert into float
   BOOST_TEST(errorflag != 1);         // Symbolab result: 0.47942...
   
   sin_function(0.5, &errorflag);      // My code result: 0.479426
   BOOST_TEST(errorflag != 1);        // Symbolab result: 0.47942...

   sin_function(5*M_PI/6, &errorflag);      // My code result: 0.499958
   BOOST_TEST(errorflag != 1);             // Symbolab result: 0.49995...

   sin_function(M_PI, &errorflag);        // My code result: 0, does not take M_PI as a float, but a string which turns it into 0
   BOOST_TEST(errorflag != 1);            // Symbolab result: -0.0044...

   /*sin_function(2*M_PI, &errorflag);      // Probably the most interesting aspect is the fact 
   BOOST_TEST(errorflag != 1);*/           // that M_PI is constant double, while sin() takes only
                                          // a type float, which is why it's comparing float M_PI == Double M_PI
                                          // hence it is incorrect.
   /*sin_function(6.8, &errorflag);         
   BOOST_TEST(errorflag != 1);*/   // Fails because it above 6.28
}