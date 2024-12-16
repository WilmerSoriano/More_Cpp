/*
   NOTE:
   This does not contain the BOOT test. 
   It simply runs the sin() function, 
   takes an input, and outputs the result.
   
   HOW TO COMPILE AND RUN:
   Inside the current directory of Sin_function.cpp
   1.) To compile: g++ Sin_function.cpp -o Sin_function
   2.) To run: 
*/

#include <iostream>
#include <cmath> // Used only for M_PI which contain a value of: PI or 3.14...etc...


using namespace std;

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
   
   if((X >= 0.0) && (X <= 2*M_PI)){ // 2*PI = 6.28318      
      for(n = 3; n <= 11; n=n+2){           // Performs factorial :
         result = (pow(X,n)/factorial(n)); // x-(X^3)/3! + (X^5)/5! - (X^7)/7! + (X^9)/9! - (X^11)/11!
         switch (n){// Add or Subtract
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

int main()
{
   int errorflag = 0;
   float value = 0.00;
   cout << "Enter Value: ";
   cin >> value;

   value = sin_function(value, &errorflag);
   
   if(errorflag == 1){
      cout << "The input is out of range:" << value << endl;
      return errorflag;
   }
   else{
      cout << "Taylor Series Result:" << value<< endl;
      return 0;
   }
}