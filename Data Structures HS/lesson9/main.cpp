/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Lesson9
//Author: Kevin Zhang
//Using classes to find area and radius of circle
#include <iostream>
#include <math.h>
using namespace std;
class Circle {
    private:
    double pi = M_PI;
    double area, circumfrence;
    public:
    
    void setAC (double radius) {
    area = pi*radius*radius;
    circumfrence = 2*pi*radius;
    }
    
    double getArea(){
        return area;
    }
    
    double getCircumfrence(){
       return circumfrence; 
    }
    
};


int main() {
    int repeat = 0;
    int r;
    while (repeat < 3) {
        cout << "Enter radius: \n" ;
        cin >> r;
        Circle circle;
        circle.setAC(r);
        cout << "circumfrence: " << circle.getCircumfrence() << endl;
        cout << "area: " << circle.getArea() << endl;
        repeat++;
    }
    return 0;
}

