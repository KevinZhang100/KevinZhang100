/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Shapes
//Author: Kevin Zhang
//Find the area of different shapes using inheritance classes
#include <iostream>
#include <math.h>
using namespace std;

class Polygon {
    protected: //protected so i can use them in other classes
    float aa;
    float bb;
    float Area;
    
    public:
    void setValues(int a, int b) { //set the values from main
        aa = a;
        bb = b;
    }
    
    float area() { //return area
        return Area;
    }
};

class Rectangle: public Polygon{ //class to find area of rectangle
    public:
    void rectangleArea() {
        float area = aa*bb;
        Area = area; //set area
    }
    
     void print() {
         float are = area(); //get area
         cout << "The area of the rectangle is: " << are << endl; //print area
     }
    
};


class Triangle: public Polygon {//class to find area of triangle
    public:
    void triangleArea() {
        float area = 0.5*aa*bb;
        Area = area;
    }
    
    void print() {
        float are = area();
         cout << "The area of the triangle is: " << are << endl;
     }
    
};

class Pentagon: public Polygon { //class to find area of pentagon
    public:
    void pentaArea() {
        float const1 = aa*aa;
        float const2 = 5*(5 + 2*sqrt(5)); //cool formula
        float area = 0.25*sqrt(const2)*const1;
        Area = area;
    }
    
    void print() {
        float are = area();
         cout << "The area of the pentagon is: " << are << ". The formula is really cool! " << endl;
     }
    
};


class Output{
    void print();
};

int main()
{
    int repeat = 0; //repeat for convinence
    while (repeat == 0) {
        int choice;
        cout << "Enter 0 for triangle, enter 1 for rectangle, enter 2 for pentagon" << endl;
        cin >> choice; //enter choice
        if (choice == 0) { //triangle
            int base, height;
            cout << "Enter base: " << endl; //get base and height
            cin >> base;
            cout << "Enter height: " << endl; 
            cin >> height;
            Triangle triangle; //create triangle object
            triangle.setValues(base, height); //set values
            triangle.triangleArea(); //use the values to find the area
            triangle.print(); //print the values
        }
        
        if (choice == 1) { //rectangle
            int length, width;
            cout << "Enter length: " << endl;
            cin >> length;
            cout << "Enter width: " << endl;
            cin >> width;
            Rectangle rectangle; //create rectangle object
            rectangle.setValues(length, width);
            rectangle.rectangleArea();
            rectangle.print();
        }
        
        if (choice == 2) { //pentagon
            float side;
            cout << "Enter side length: " << endl;
            cin >>  side;
            Pentagon pentagon; //create pentagon object
            pentagon.setValues(side, -1); //not using b
            pentagon.pentaArea();
            pentagon.print();
        }
        
        cout << "Enter 0 to try again or any other int to stop: \n";
        cin >> repeat;
    }
    return 0;
}






