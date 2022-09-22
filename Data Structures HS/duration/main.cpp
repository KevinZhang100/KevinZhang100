/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Duration
//Author: Kevin Zhang
//Do math to a Duration Object
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;
class Duration {
    private:
    int hrs, min, sec;
    int totSec = 0;
    int sign = 1;
    
    public:
    Duration (int inith, int initm, int inits) { //constructor
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
    
    Duration (int initsec) { //constructor, converts seconds into hours and minutes, same process and the previous method
        hrs = initsec/3600;
        int extra = initsec%3600;
        min = extra/60;
        sec = extra%60;
    }
    
    int totSeconds () { //gets total seconds
        totSec = hrs*60*60 + min *60 + sec;
        return totSec;
    }
    
    Duration operator + (Duration other) { //add two durations
        hrs += other.getHrs(); //add hours, minutes, and seconds from 2nd duration
        min += other.getMin();
        sec += other.getSec();
        Duration added = Duration(hrs, min, sec); 
        return added;
    }
    
    Duration operator - (Duration other) { //subtracts two durations
        hrs = hrs - other.getHrs();//subtracts hours, minutes, and seconds from 2nd duration
        min = min - other.getMin();
        sec = sec - other.getSec();
        Duration subtracted = Duration(hrs, min, sec);
        return subtracted;
        
    }
    
    Duration operator * (double constant) { //multiplies duration by constant
        int totsec1 = totSeconds(); //gets total seconds of the duration
        double tot = totsec1*constant; //multiply by the constant 
        tot = round(tot); //round 
        Duration multiplied = Duration(tot); //create new Duration object with the seconds
        return multiplied;
    }
    
    Duration operator / (double constant) { //divides duration by constant
        int totsec1 = totSeconds(); //same thing as multiply except you divide
        double tot = totsec1/constant;
        tot = round(tot);
        Duration divided = Duration(tot);
        return divided;
    }
    
    double operator / (Duration other) { //gets ratio of a duration divided by  another duration
        double totsec1 = totSeconds(); //get total seconds of first Duration
        hrs = other.getHrs(); //sets the hours, minutes, and seconds to the second duration
        min = other.getMin();
        sec = other.getSec();
        double totsec2 = totSeconds(); //get the total seconds for the second duration
        double tot = totsec1/totsec2; //divide for ratio
        return tot;
    }
    
    operator const char* () { //conversion operator
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
    
    int getHrs() {
        return hrs;
    }
    
    int getMin() {
        return min;
    }
    
    int getSec() {
        return sec;
    }
};

int main()
{
    int repeat = 0; //repeat for convinence
    while (repeat == 0) {
        int hrs, min, sec, hrs2, min2, sec2;
        double constant;
        int choice;
        cout << "Enter:\n1 to add two durations\n2 to substract two durations\n3 to multiply a duration by a constant\n";
        cout << "4 to divide a duration by a constant\n5 to get the ratio between two durations\n"; //let user choose
        cin >> choice;
        cout << "Enter the hours of the duration: " <<endl; //enter duration
        cin >> hrs;
        cout << "Enter the minutes of the duration: " <<endl;
        cin >> min;
        cout << "Enter the seconds of the duration: " <<endl;
        cin >> sec;
        Duration duration = Duration(hrs, min, sec);
        
        if (choice == 1 || choice == 2 || choice == 5) { //enter another duration depending on choice
           cout << "Enter the hours of another duration: " <<endl;
           cin >> hrs2;
           cout << "Enter the minutes of another duration: " <<endl;
           cin >> min2;
           cout << "Enter the seconds of another duration: " <<endl;
           cin >> sec2;
           Duration duration2 = Duration(hrs2, min2, sec2);
           
            if (choice == 1) {
                cout << "The addition of duration 1 and duration 2: " << (duration+duration2)<< endl; //add
            }
            
            if (choice == 2) {
                 cout << "The subtraction of duration 2 from duration 1: " << (duration-duration2)<< endl; //subract
            }
            
            if (choice == 5) {
                cout <<"The ratio of duration1 to duration2: " <<(duration/duration2) << ":1" << endl; //ratio
            }
        }
        
        if (choice == 3) {
            double cons;
            cout << "Enter a constant to multiply the duration by: " << endl; //multipy
            cin >> cons;
            cout << "The product is: " << (duration*cons)<< endl;
        }
        if (choice == 4) {
            double cons;
            cout << "Enter a constant to divide the duration by: " << endl; //divide
            cin >> cons;
            cout << "The quotient is: " << (duration/cons)<< endl;
        }
        
        cout << "Enter 0 to try again or any other int to stop: \n";
        cin >> repeat;
    }
    return 0;
}



