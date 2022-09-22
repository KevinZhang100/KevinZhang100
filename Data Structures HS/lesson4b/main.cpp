/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Lesson4b
//Author: Kevin Zhang
//use userinput strings to make a 2D array
#include <iostream>
using namespace std;

int main()
{
    string a, b, c;
    cout<<"Enter 3 Strings: ";
    cin >> a >> b >> c;
    string arr [3][3] = {{a, b, c}, {a, b, c}, {a, b, c}};
     for (int i = 0; i < 3; i++) {
         for (int j = 0; j < 3; j++) {
        cout << arr[i][j];
         }
         cout << "\n";
     }
     
     cout<<endl;
     string arr2 [3][3] = {{a, a, a}, {b, b, b}, {c, c, c}};
     for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
        cout << arr2[i][j];
         }
         cout << "\n";
     }
     
    return 0;
}






