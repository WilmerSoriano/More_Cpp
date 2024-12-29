#include "Time.h"
#include <iostream>
#include <istream>
#include <iomanip>
#include <sstream>
#include <string>
#include <exception>

   Time ::Time(int hour, int minute, int second )  //NOTEtoSelf:add Zero if ostream doesn't work
   :_hour{hour}, _minute{minute}, _second{second}{rationalize();};
   
   //Time::Time() : Time{00, 00, 00}{};
   
   Time Time::operator+(Time time)//the ability to add itself
   {
      return Time{_hour + time._hour,
      _minute +  time._minute,
      _second + time._second};
      /*Time t{*this};
      t._hour = _hour + time._hour;
      t._minute = _minute +  time._minute;
      t._second = _second + time._second;
      t.rationalize();<- you don't on update version because it is alreafy called in constructor*/
      //return t;
   }
   
   Time& Time::operator++()//(pre increment) ++time
   {
      _second++;       //add the size of new second from user
      rationalize();   // checks it
      return *this;    //returns the new result
   }

   Time Time::operator++(int) //the ability to increment (post increment) time ++
   {
      Time old_time = *this; //save the time we original use 
      operator++();          //go to the method above this one
      return old_time;       //update the time from method above and retunr th eold one 
      // just like time++ instead of ++time.
      /*Time time{*this};
      _second++;
      rationalize();
      return time;*/
   }
   
   
   std::ostream& operator <<(std::ostream& ost,const Time& time) 
   {
      //ost <<std::setfill('0')<<std::setw(2)<<time._hour<<":"<<time._minute<<":"<<time._second;
      ost <<std::setfill('0')
      <<std::setw(2)<< time._hour << ":" 
      <<std::setw(2)<< time._minute << ":" 
      <<std::setw(2)<< time._second;
      
      //time.rationalize();

      return ost;
   }//the ability to return a string of it self and default value
  

   std::istream& operator >>(std::istream& ist, Time& time)
   {
      std::string copy;      
      char c{':'};
      
      ist >> copy;
      std::istringstream iss{copy};
      
      if(iss >>time._hour>> c >>time._minute>> c >>time._second) //taking input with colon
      {
         time.rationalize();
         return ist;
         
      }
      else if(iss >>time._hour>>time._minute>>time._second) // taking input without colon
      {
         time.rationalize();
         return ist;
      }
      else{
      throw std::runtime_error("Format error: HH:MM:SS");
      }
      
   }//the ability to take in time input
   
   void Time::rationalize()
   {
      
      while(_second > 59){_second = _second - 60; ++_minute;} //bruh... would have used mudolo ex:My_value%60, conatins it there
      while(_minute > 59){_minute = _minute - 60; ++_hour;}
      while(_hour > 23){_hour =_hour - 24;}
      
      while(_second < 0){_second = 60 + _second; --_minute;}
      while(_minute < 0){_minute = 60 + _minute; --_hour;}
      while(_hour < 0){_hour =24 + _hour;}
      
      
   }
   
   int Time::compare(const Time& time)
   {
      if(_hour   < time._hour  ) return -1;
      if(_hour   > time._hour  ) return 1;
      if(_minute < time._minute) return -1;
      if(_minute > time._minute) return 1;
      if(_second < time._second) return -1;
      if(_second > time._second) return 1;
      return 0;
   }
