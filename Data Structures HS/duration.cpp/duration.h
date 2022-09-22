/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//duration
//Author: Kevin Zhang
//Duration Header

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <cmath>

#ifndef DURATION_H
#define DURATION_H

using namespace std;
class Duration {
    private:
    int hrs = 0;
    int min = 0;
    int sec = 0;
    int totSec = 0;
    int sign = 1;
    
    public:
      Duration(int inith, int initm, int inits);
      Duration(int initm, int inits);
      Duration (int initsec);
      Duration();
      int totSeconds();
      Duration operator + (Duration other);
      Duration operator - (Duration other);
      Duration operator * (double constant);
      Duration operator / (double constant);
      double operator / (Duration other);
      int getHrs();
      int getMin();
      int getSec();
      operator const char*();
      void randomize();
};
    
    
    Duration::Duration() {
    }
    
    Duration::Duration(int inith, int initm, int inits) { //constructor
        hrs = inith;
        min = initm;
        sec = inits;
        
        if (initm > 60) { //makes sure time is structured correctly (minutes and seconds are less than 60)
            hrs = hrs + initm/60; //adds to hours for every 60 minutes
            min = initm%60; //remainder for the minutes
        }
        
        if (inits > 60) { //basically same concept for seconds as well
            hrs = hrs + inits/3600;
            int extra = inits%3600;
            min = min + extra/60;
            sec = extra%60;
        }
    }
    
    Duration::Duration(int initm, int inits) { //constructor
        min = initm;
        sec = inits;
        
        if (initm > 60) { //makes sure time is structured correctly (minutes and seconds are less than 60)
            hrs = hrs + initm/60; //adds to hours for every 60 minutes
            min = initm%60; //remainder for the minutes
        }
        
        if (inits > 60) { //basically same concept for seconds as well
            hrs = hrs + inits/3600;
            int extra = inits%3600;
            min = min + extra/60;
            sec = extra%60;
        }
    }
    
    Duration::Duration(int initsec) { //constructor, converts seconds into hours and minutes, same process and the previous method
        hrs = initsec/3600;
        int extra = initsec%3600;
        min = extra/60;
        sec = extra%60;
    }
    
    int Duration::totSeconds() { //gets total seconds
        totSec = hrs*60*60 + min *60 + sec;
        return totSec;
    }
    
    Duration Duration::operator + (Duration other) { //add two durations
        hrs += other.getHrs(); //add hours, minutes, and seconds from 2nd duration
        min += other.getMin();
        sec += other.getSec();
        Duration added = Duration(hrs, min, sec); 
        return added;
    }
    
    Duration Duration::operator - (Duration other) { //subtracts two durations
        hrs = hrs - other.getHrs();//subtracts hours, minutes, and seconds from 2nd duration
        min = min - other.getMin();
        sec = sec - other.getSec();
        Duration subtracted = Duration(hrs, min, sec);
        return subtracted;
        
    }
    
    Duration Duration::operator * (double constant) { //multiplies duration by constant
        int totsec1 = totSeconds(); //gets total seconds of the duration
        double tot = totsec1*constant; //multiply by the constant 
        tot = round(tot); //round 
        Duration multiplied = Duration(tot); //create new Duration object with the seconds
        return multiplied;
    }
    
    Duration Duration::operator / (double constant) { //divides duration by constant
        int totsec1 = totSeconds(); //same thing as multiply except you divide
        double tot = totsec1/constant;
        tot = round(tot);
        Duration divided = Duration(tot);
        return divided;
    }
    
    double Duration::operator / (Duration other) { //gets ratio of a duration divided by  another duration
        double totsec1 = totSeconds(); //get total seconds of first Duration
        hrs = other.getHrs(); //sets the hours, minutes, and seconds to the second duration
        min = other.getMin();
        sec = other.getSec();
        double totsec2 = totSeconds(); //get the total seconds for the second duration
        double tot = totsec1/totsec2; //divide for ratio
        return tot;
    }
    
    Duration::operator const char* () { //conversion operator
        ostringstream timed;
         string signer;// adds sign to the beginning
       
       if (totSeconds() > -1) { //if total seconds are positive, no sign, if negative there is a sign
            sign = 1;
           
       }
       if (totSeconds() < 0) {
            sign = -1;
        }
        
       if (sign == -1) {
         signer = "-";  
        }
        
        hrs = abs(hrs); //absolute values the time
        min = abs(min);
        sec = abs(sec);
        
        string hh, mm, ss;
        if (hrs < 10) { //adds a zero to the front if the time value is less than 10
            hh = "0";
        }
        if (min < 10) {
            mm = "0";
        }
        if (sec < 10) {
            ss = "0";
        }
        
       hh = hh + to_string(hrs);
       mm = mm + to_string(min);
       ss = ss + to_string(sec);
        timed << signer << hh << ":" <<mm<< ":"<<ss;
        string theTime = timed.str();
        return theTime.c_str();
    }
    
    int Duration::getHrs() {
        return hrs;
    }
    
    int Duration::getMin() {
        return min;
    }
    
    int Duration::getSec() {
        return sec;
    }
    
    void Duration::randomize() {
	hrs = rand() % 24;
	min = rand() % 60;
	sec = rand() % 60;
}

#endif

