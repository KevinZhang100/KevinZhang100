/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Lesson3b
//Author: Kevin Zhang
//find circumfrence and area from radius
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    float r;
    cout<<"Enter the radius\n";
    cin>>r;
    float area = M_PI * r *r;
    cout<<"area is: "<<area<<"\n";
    float cirum = M_PI * 2 *r;
    cout<<"circumfrence is: "<<cirum<<"\n";
    
}

