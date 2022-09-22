/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//BigMath
//Author: Kevin Zhang
//Add or subtract 2 big numbers
#include <iostream>
#include "BigMath.h"
using namespace std;

int main()
{
    int loop = 0; //loop because convinence
    while (loop == 0) {
        string number1, number2, total;
        int addSub;
        cout << "Enter number 1: " << endl;
        cin >> number1;
        cout << "Enter number 2: " << endl;
        cin >> number2;
 	    BigMath num1 = num1.toNum(number1);
 	    BigMath num2 = num2.toNum(number2);
 	    cout << "Enter 1 to add or 2 to subtract" << endl;
 	    cin >> addSub;
 	    if (addSub == 1) {
 	        BigMath* tot = num1 + num2;
 	        total = tot->toString();
 	        cout << "The number you get is: " << total << endl;
 	    }
 	    if (addSub == 2) {
 	        BigMath* tot = num1 - num2;
 	        total = tot->toString();
 	        cout << "The number you get is: " << total << endl;
 	    }
 	    cout << "Enter 0 to try again or any other int to stop: \n";
 	    cin >> loop;
    }
 	return 0;
}

