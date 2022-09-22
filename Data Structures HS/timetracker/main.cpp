/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//TimeTracker
//Author: Kevin Zhang
//Using classes to do various things with time
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Time {
    private: //private variables
    int hr, mi, se;
    int sign = 1; //determine whether time is positive or negative
    int sec; //keeps track of total seconds
    
    public: 
    Time (int inith, int initm, int inits) { //constructor
        hr = inith;
        mi = initm;
        se = inits;
        
        if (initm > 60) { //makes sure time is structured correctly (minutes and seconds are less than 60)
            hr = hr + initm/60; //adds to hours for every 60 minutes
            mi = initm%60; //remainder for the minutes
        }
        
        if (inits > 60) { //basically same concept for seconds as well
            hr = hr + inits/3600;
            int extra = inits%3600;
            mi = mi + extra/60;
            se = extra%60;
        }
    }
    
    Time (int initsec) { //constructor, converts seconds into hours and minutes, same process and the previous method
        hr = initsec/3600;
        int extra = initsec%3600;
        mi = extra/60;
        se = extra%60;
    }
    
    int totSeconds () { //gets total seconds
        sec = hr*60*60 + mi *60 + se;
        return sec;
    }
    
    Time add(Time other) { // first method, adds two time objects
        int timing = totSeconds() + other.totSeconds(); //adds all the seconds up
		Time newer = Time(timing); 
			return newer;
    }
    
    Time subtract(Time other) { //second method, subtracts two time objects
      int timing = totSeconds() - other.totSeconds();
		Time newer = Time(timing);
			return newer;
    }

    Time increaseBy(int h, int m, int s) { //third method, adds values to time object
    h = hr +h;
    m = mi +m;
    s = se +s;
    Time newer = Time(h, m, s);
    return newer;
   }

    Time increaseBy(int s) { //fourth method, adds seconds to time object
    s = se + s;
    Time newer = Time(hr, mi, s);
    return newer;
   }
   
   string toString () { //what gets printed out
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
        
        abs(hr); //absolute values the time
        abs(mi);
        abs(se);
        
        string hh, mm, ss;
        if (hr < 10) { //adds a zero to the front if the time value is less than 10
            hh = "0";
        }
        if (mi < 10) {
            mm = "0";
        }
        if (se < 10) {
            ss = "0";
        }
        
       hh = hh + to_string(hr);
       mm = mm + to_string(mi);
       ss = ss + to_string(se);
      string s = signer + hh + ":" + mm + ":" + ss; //puts everything into time format
      return s;
   }
};

int main() {
    int repeat = 0; //repeat for convinence
    while (repeat == 0) {
        int hrs, mins, secs;
        cout << "Enter hours: \n"; //enter values
        cin >> hrs;
        cout << "Enter minutes: \n";
        cin >> mins;
        cout << "Enter seconds: \n";
        cin >> secs;
        Time timed = Time(hrs, mins, secs); //creates time object
        cout << "Your entered time is: " << timed.toString() << endl; //prints the time
        int choice; //select which method
        cout << "Enter 1 to add two time objects, enter 2 to subtract time objects, \nenter 3 to increase time by given hours minutes and seconds, enter 4 to increase time by given seconds\n";
        cin >> choice;
        
        if (choice == 1){ //method 1
            int hr, min, sec;
            cout << "Enter additional hours: \n";
            cin >> hr;
            cout << "Enter additional minutes: \n";
            cin >> min;
            cout << "Enter additional seconds: \n";
            cin >> sec;
            Time timed2 = Time(hr, min, sec); //creates another time object
			Time temp = timed.add(timed2);//calls add method
			cout << temp.toString()<< endl;
        }
        if (choice == 2){ //method 2
           int hr, min, sec;
            cout << "Enter additional hours: \n";
            cin >> hr;
            cout << "Enter additional minutes: \n";
            cin >> min;
            cout << "Enter additional seconds: \n";
            cin >> sec;
            Time timed2 = Time(hr, min, sec);
			Time temp = timed.subtract(timed2);
			cout << temp.toString()<< endl; 
        }
        
        if (choice == 3){ //method 3
            int h, m, s;
            cout << "Enter increment hours: \n";
            cin >> h;
            cout << "Enter increment minutes: \n";
            cin >> m;
            cout << "Enter increment seconds: \n";
            cin >> s;
            Time timed2 = timed.increaseBy(h, m, s); //calls increaseBy method
           cout << timed2.toString() << endl;
        }
        
        if (choice == 4){ //method 4
            int s;
            cout << "Enter increment seconds: \n";
            cin >> s;
            Time timed2 = timed.increaseBy(s);
           cout << timed2.toString() << endl;
        }
        else { //wrong input
            cout << "Wrong input \n";
        }
        cout << "Enter 0 to try again or any other int to stop: \n";
        cin >> repeat;
    }
    return 0;
}






