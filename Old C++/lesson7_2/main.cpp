/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Lesson7b
//Author: Kevin Zhang
//Write a function that displays true if the integer is a perfect number
#include <iostream>
using namespace std;
void perfect (int number, bool& isPerfect ) {
    int i = 1;
    int count = 0;
    while (i < number) {
        int temp = number%i;
        if (temp == 0) {
            count = count + i;
        }
        i++;
    }
    if (count == i) {
        isPerfect= true;
    }
}

int main()
{
    int num = 0;
    cout << "Enter an integer: " <<endl;
    cin >> num;
    bool isPerfect = false;
    perfect(num, isPerfect);
    if (isPerfect){
        cout << "true";
    }
    else {
    cout << "false";
    }
}






