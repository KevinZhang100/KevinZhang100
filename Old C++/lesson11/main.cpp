/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Lesson11
//Author: Kevin Zhang
/*Practicing Multiple Inheritance, attempt at trying to determine if a certain shape is 
possible or not based on 2 angles and its vertical/horizontal symmetry*/
#include <iostream>
using namespace std;
class Quadrilateral {
    protected:
    int a, b;
    bool horizontal, vertical, equal;
    bool cont = true;
    
    public: 
    void setquad(int ang, int ang2, bool hori, bool vert, bool eq){
        a = ang;
        b = ang2;
        horizontal = hori;
        vertical = vert;
        equal = eq;
        if (a > 359 || a < 1 || b > 359 || b < 1) {
            cout << "Not Quadrilateral" << endl;
            cont = false;
        }
        if (cont == true) {
            cout << "Quadrilateral, assuming the shape has 4 sides and the sum of all angles add to 360" << endl;
        }
    }
    
    bool getCont(){
        return cont;
    }
};

class Trapezoid: virtual public Quadrilateral{ //prevent ambiguity
    public:
   void isTrap(){
        int tot = a+b;
        if (a == b || tot == 180) {
                 cout << "Is Trapezoid" << endl;
             }
        }
};

class Kite: virtual public Quadrilateral{
    public:
    void isKite() {
        if (horizontal == true && vertical == true) {
            cout << "Is Kite" << endl;
        }
    }
};

class Parallelogram: public Trapezoid{
    public:
    void isPara() {
        int tot = a+b;
        if (a == b || tot == 180) {
            if (horizontal == false && vertical == false) {
            cout << "Is Parallelogram" << endl;
            }
        }
        else {
            isTrap();
        }
    }
};

class Isosceles: public Trapezoid{
    public:
    void isIso(){
        int tot = a+b;
        if (a == b || tot == 180) {
             if (vertical == true) {
                 cout << "Is Isosceles Trapezoid" << endl;
             }
        }
        else {
            isTrap();
        }
    }
};

class Rhombus: public Parallelogram, public Kite{
    public:
    void isRho() {
        if (equal) {
            if (horizontal == true && vertical == true) {
                cout << "Is Rhombus" << endl;
            }
        }
        else {
            isPara();
            isKite();
        }
    }
    
};

class Rectangle: public Parallelogram, public Isosceles{
    public:
     void isRec() {
        if (a == 90 && b == 90) {
            if (horizontal == true && vertical == true){
                cout << "Is Rectangle" << endl;
            }
        }
        else {
           isPara(); 
        }
    }
    
};

class Square: public Rhombus, public Rectangle{
    public:
    void isSquare() {
        if (a == 90 && b == 90) {
            if (horizontal == true && vertical == true){
                if (equal) {
                    cout << "Is Square " << endl;
                }
            }
        }
        else {
            isRec();
            isRho();
        }
    }
};

int main()
{
    int angle, angle2;
    bool horizontal, vertical, equal;
    cout << "Enter an angle: " << endl;
    cin >> angle;
    cout << "Enter another angle: " << endl;
    cin >> angle2;
    cout << "does this shape have horizontal symmetry (enter 1 for true or 0 for false)" << endl;
    cin >> horizontal;
    cout << "does this shape have vertical symmetry (enter 1 for true or 0 for false)" << endl;
    cin >> vertical;
    cout << "are all lengths equal to each other (enter 1 for true or 0 for false)" << endl;
    cin >> equal;
    Square quad;
    quad.setquad(angle, angle2, horizontal, vertical, equal);
    bool tru = quad.getCont();
    if(tru == true) {
        quad.isSquare();
    }
    return 0;
}





