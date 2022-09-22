/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Lesson12
//Author: Kevin Zhang
//Modifying Date class

#include <iostream>
using namespace std;

class Date
{
private:
   int day, month, year;
   int lastDay;
   int monthDays;
   void setDay (){
       if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month  == 10 || month == 12) {
           lastDay = 31;
       }
       
       if (month == 4 || month == 6 || month == 9 || month == 11) {
           lastDay = 30;
       }
       
       if (month == 2) {
           int leap = year%4;
           if (leap == 0) {
               lastDay = 29;
           }
           else {
               lastDay = 28;
           }
           
       }
   }
   
     void dateAdd() {
       setDay();
       if (day > lastDay) {
          day = 1;
          month ++;
       }
       
       if (month > 12) {
           month = 1;
           year++;
       }
   }
   
   void dateSubtract() {
       setDay();
       if(day < 1) {
           month--; 
           setDay();
           day = lastDay;
       }
       
       if(month < 1) {
           year--;
           month = 12;
       }
   }
   
   void monthToDays() {
       int constMonth = month;
       monthDays = 0;
       for (int i = 1; i < constMonth; i++) {
           month = i;
           setDay();
           monthDays =+ lastDay;
       }
       month = constMonth;
   }
 
public:
   Date (int inMonth, int inDay, int inYear)
        : month (inMonth), day(inDay), year (inYear) {};
        
   
   Date& operator ++ () // prefix increment
   {
      ++day;
      dateAdd();
      return *this;
   }

   Date& operator -- () // prefix decrement
   {
      --day;
      dateSubtract();
      return *this;
   }

   Date operator ++ (int) // postfix increment
   {
      Date copy(month, day, year);
      ++day;
      dateAdd();
      return copy;
   }

   Date operator -- (int) // postfix decrement
   {
      Date copy(month, day, year);
      --day;
      dateSubtract();
      return copy;
   }
   
   operator const int() { 
       int tot = year*365 + monthDays + day;
       return tot;
   }
   

   void DisplayDate()
   {
      cout << month << " / " << day << " / " << year << endl;
   }
};

int main ()
{
   Date holiday (12, 31, 2016); // Dec 25, 2016

   cout << "The date object is initialized to: ";
   holiday.DisplayDate ();

   ++holiday; // move date ahead by a day
   cout << "Date after prefix-increment is: ";
   holiday.DisplayDate ();

   --holiday; // move date backwards by a day
   cout << "Date after a prefix-decrement is: ";
   holiday.DisplayDate ();

   return 0;
}

