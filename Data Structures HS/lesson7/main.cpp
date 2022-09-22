/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Lesson7
//Author: Kevin Zhang
//find circumfence and area in a void method, find volume for sphere and cylinder in overloaded methods
#include <iostream>
#include <math.h>
using namespace std;
double area;
double circumfrence; 

void aandc (double radius) {
    area = radius*radius*M_PI;
    circumfrence = radius*2*M_PI;
}

double volume (double radius) {
    double vol = 4/3*M_PI*radius*radius*radius;
    return vol;
}

double volume (double radius, double height) {
    double vol = area*height;
}

int main()
{
    double radius, height;
    cout << "Enter radius: "<<endl;
    cin >> radius;
    aandc(radius);
    cout << "Area: " << area << endl;
    cout << "Circumfrence: " << circumfrence << endl;
    cout << "Enter height for cylinder: " << endl;
    cin >> height;
    cout << volume(radius) << endl;
    cout << volume(radius, height) << endl;
    return 0;
}

