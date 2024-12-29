#include <iostream>
#include <istream>
#include <iomanip>
#include <sstream>
#include <exception>

#ifndef __TIME_H
#define __TIME_H

class Time
{
   public:
   Time(int hour = 0, int minute = 0, int second = 0); //default to zero's
   
   Time operator+(Time time);
   
   Time& operator++(); //pre Inc
   Time operator++(int);//post Inc
   
   inline bool operator ==(const Time& time) {return (compare(time) == 0);}
   inline bool operator !=(const Time& time) {return (compare(time) != 0);}
   inline bool operator < (const Time& time) {return (compare(time) < 0);}
   inline bool operator <=(const Time& time) {return (compare(time) <= 0);}
   inline bool operator > (const Time& time) {return (compare(time) > 0);}
   inline bool operator >=(const Time& time) {return (compare(time) >= 0);}
   
   friend std::ostream& operator <<(std::ostream& ost,const Time& time);
   friend std::istream& operator >>(std::istream& ist, Time& time);
   
   private:
   int _hour;
   int _minute;
   int _second;
   
   int compare(const Time& time);
   void rationalize();
};
#endif