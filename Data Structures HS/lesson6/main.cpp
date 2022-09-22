/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Lesson6
//Author: Kevin Zhang
//add 2 same length arrays in reverse
#include <iostream>
using namespace std;
int main()
{
    int arr1[] = {1, 3, 5, 8};
    int arr2[] = {2, 2, 4, 12};
    int length = sizeof(arr1)/sizeof(arr1[0]);
    int arr3[length];
    int count = 0;
    for (int i = length-1; i >= 0; i--){
        arr3[count] = arr1[i] + arr2[i];
        count++;
    }
    for (int i = 0; i<length; i++) {
        cout << arr3[i] << " ";
    }
    return 0;
}

