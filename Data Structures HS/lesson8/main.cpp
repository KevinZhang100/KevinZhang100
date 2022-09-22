/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Lesson8
//Author: Kevin Zhang
//accept values and print array using pointers
#include <iostream>
using namespace std;
int main()
{
    int *ptr;
    int arr[5];
    ptr = arr;
    int a, b, c, d, e;
    cout << "Enter 5 ints: \n";
    cin >> a >> b >> c >> d >> e;
    *(ptr+0) = a;
    *(ptr+1) = b;
    *(ptr+2) = c;
    *(ptr+3) = d;
    *(ptr+4) = e;
    for (int i = 0; i < 5; i++){
        cout << *(ptr+i);
    }
    
    return 0;
}


