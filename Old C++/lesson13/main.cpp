/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Lesson13
//Author: Kevin Zhang
//use static_cast
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
    
    double arr[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    srand(time(0));
    for (int i = 0; i < 10000; i++) {
        double six = rand()/(RAND_MAX)+1 +(rand()%6);
        int randomed = static_cast<int>(six);
        double six2 = rand()/(RAND_MAX)+1 +(rand()%6);
        int randomed2 = static_cast<int>(six2);
        arr[(randomed+randomed2-1)]++;
    }
    
    for (int i = 0; i < 12; i++) {
        double ratio = arr[i];
        cout << "ratio for side " << (i+1) << ":" << ratio << endl;
    }
}



