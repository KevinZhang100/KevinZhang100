/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Conversions
//Author: Kevin Zhang
//Converting between bases
#include <iostream>
#include <math.h>
using namespace std;
string toBase(int decimal, int base) { //convert from base 10 to specified base
    int i = decimal; 
    string convert; //the return string with the converted number
    while (i > 0) { //divide the number by the base until you cant anymore
        int remain = i%base; //the remainder
        if (remain > 9) { //for base 16 so i dont have to rewrite method
           if (remain == 10){ //the remainders to base 16 letters
              convert = 'A' + convert; 
           }
           if (remain == 11){
              convert = 'B' + convert; 
           }
           if (remain == 12){
              convert = 'C' + convert;
           }
           if (remain == 13){
              convert = 'D' + convert; 
           }
           if (remain == 14){
              convert = 'E' + convert; 
           }
           if (remain == 15){
              convert = 'F' + convert; 
           }
        }
        else {
            convert = to_string(remain) + convert; //put in the remainder with the rest of the converted number
        }
        i = i/base; //divide i for the next loop
    }
    return convert;
}

string toBase16(int decimal) { //convert from base 10 to base 16
    string convert = toBase(decimal, 16); //call the base conversion method
    return convert;
}

int toInteger(string number, int base) { //convert from input base to base 10 
    int length = number.length(); //keep the original length as a constant
    int count = number.length()-1; //the power the base is going to be raised to
    int convert = 0; //
    for (int i = 0; i < length; i++) {
        char temp = number[0]; //gets the first digit
        int num = temp - 48; //substracts because ascii table
        if (num > 9) { //if entered string was base 16 then stops the method
            return -1;
        }
        num = num*pow(base, count); //how to convert
        convert = convert+num; 
        number.erase(0,1); //remove the first digit
        count--; //reduces power
    }
    
    return convert;
}

int toInteger16(string number) { //convert from base 16 to base 10
    int length = number.length(); //basically same as the other method
    int count = number.length()-1;
    int convert = 0;
    for (int i = 0; i < length; i++) {
        char temp = number[0];
        int num = temp - 48;
        if (num > 9) { //if its a letter reduce by another 7 because ascii
            num = num - 7;
        }
        num = num*pow(16, count);
        convert = convert+num;
        number.erase(0,1);
        count--;
    }
    return convert;
}

int main()
{
    int bruh = 0; //loop because convinence
    while (bruh == 0) {
    string number;
    int decimal, base;
    cout << "Enter a number for the string:\n";
    cin >> number;
    cout << "Enter a base:\n";
    cin >> base;
    cout << "Enter a decimal:\n";
    cin >> decimal;
    cout << "Converting from integer to specified base: " << toBase(decimal, base) << endl;
    cout << "Converting from integer to base 16: " << toBase16(decimal) <<endl;
    cout << "Converting from string to base 10: " << toInteger(number, base) << endl;
    cout << "Converting from base 16 to base 10: " << toInteger16(number) << endl;
    cout << "Enter 0 to continue, enter another digit to not" << endl;
    cin >> bruh;
    }
    return 0;
    
}













