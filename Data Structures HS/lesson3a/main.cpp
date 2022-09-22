/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Lesson3a
//Author: Kevin Zhang
//demonstrate the size of an unsigned integer and a normal integer are the same and both are smaller than long integer
#include <iostream>
using namespace std;
int main()
{
    cout<<sizeof(unsigned int)<<endl; //4 bytes
    cout<<sizeof(int)<<endl; //4 bytes
    cout<<sizeof(long int)<<endl; //8 bytes, greater than 4
    cout<<sizeof(long double)<<endl; //16 bytes
    return 0;
}




