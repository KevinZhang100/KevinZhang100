/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Lesson10
//Author: Kevin Zhang
//Practicing Inheritance
#include <iostream>
using namespace std;
class Shape {
    private:
    bool poly = true;
    bool trident = true;
    int counted;
    
    public:
    
    void countSides (int sides) {
        counted = sides;
        if (counted < 3){
           poly = false;
           trident = false;
       }
       
    }
   bool getPolygon() { return poly;}
   bool getTriangle() { return trident;}
   int getCount() { return counted;}
    
};

class Polygon: public Shape{
    public:
    void polygon(){
        bool poly2;
        poly2 = getPolygon();
        if (poly2) { 
         cout << "This is a Polygon!" << endl;
      }
      else {
         cout << "Not a polygon :(" << endl;
      }
    }
};

class Triangle: public Polygon{
    public:
    void triangle (){
        bool tri;
        tri = getTriangle();
        if (tri){
            int count = getCount();
            cout << "You can fit " << count << " triangles in this polygon from the center to 2 vertexes!" << endl;
        }
        
        else { 
            cout << "Not a polygon :(" << endl;
        }
    }
};

int main() {

    int count;
    cout << "Type in a number of sides: " << endl;
    cin >> count;
    Triangle tried;
    tried.countSides(count);
    tried.polygon();
    tried.triangle();
}




