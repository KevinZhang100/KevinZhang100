/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Lesson1 
//Author: Kevin Zhang
//using integers
#include <iostream>

int main()
{
    using namespace std; //so i dont have to type it
    int input, input2, input3, input4;
    cout << "Enter a number\n"; //enter a number
    cin >> input;
    cout << "Enter 3 more numbers\n";
    cin >> input2 >> input3 >> input4; //enter multiple numbers
    cout << "Multiply 1 and 2: " << input*input2 << endl; //multiply
    if (input+input2 < input3+input4){ //determine which 2 additions is greater
         cout << "first and second number is less than 3rd and 4th number";
    }
     else cout << "first and second number is not less than 3rd and 4th number";
    return 0;
}

