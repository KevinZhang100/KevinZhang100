/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Lesson5
//Author: Kevin Zhang
//bitwise two booleans from user input
#include <iostream>
using namespace std;

int main() {
    bool a, b;
    cout<<"Input 2 booleans\n";
    cin>> a >> b;
    bool c = a|b;
    cout<<"inclusive or: "<< c << endl;
    c = a&b;
    cout<<"and: "<< c << endl;
    c = a^b;
    cout<<"exclusive or: "<< c << endl;
}


