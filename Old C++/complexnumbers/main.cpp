/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//ComplexNumbers
//Author: Kevin Zhang
//Do stuff with complex numbers
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
using namespace std;

class Complex {
    private:
    int a;
    int b;
    
    public:
    Complex (int real, int imaginary){ //initialize a complex numeber
       a = real;
       b = imaginary;
    }
    
    Complex conjugate() { //returns the complex conjugate
        b = b*-1; //imaginary part of conjugate is negative
        Complex conju(a, b);
        return conju;
    }
    
    
    double norm() { //gets the norm of a complex number, which is sqrt(a^2+b^2)
       double norm = a*a + b*b;
       norm = sqrt(norm);
       return norm;
    }
    
    double real() { //return real part of complex number
        return a;
    }
    
    double imag() { //return imaginary part of complex number
        return b;
    }
    
    double dotProduct(Complex other) { //get dot product
        double tot = a*other.real() + b * other.imag(); //dot purduct forumla is a1*a2 + b1*b2;
        return tot;
    }
    
    Complex scalarProduct(double value) { //get scalar product, multiply a and b by a value
        a = a*value;
        b = b*value;
        Complex scalar(a, b);
        return scalar;
    }
    
    double angleBetween(Complex other) { //the equation I used was arctan((a1*b2 - b1*a2)/(a1*a2+b1*b2)) in which a and b are all real numbers
        double numerator = a * other.imag() - b*other.real(); //get the numerator (a1*b2 - b1*a2)
        double denominator = a * other.real() + b * other.imag(); //get the denominator (a1*a2+b1*b2)
        double tot = atan(numerator/denominator); //arctan it
        double convert = 180/M_PI; //convert rad to degrees
        tot = tot * convert;
        if (tot < 0) { //if angle is less than 0 add 360
            tot = tot + 360;
        }
        return tot;
    }
    
    Complex operator + (Complex other) { // add complex numbers
        a+= other.real();
        b+= other.imag();
        Complex comp(a, b);
        return comp;
    }
    
    Complex operator - (Complex other) {  //subtract complex numbers 
        a = a - other.real();
        b = b - other.imag();
        Complex comp(a, b);
        return comp;
    }
    
    Complex operator * (Complex other) { //multiply complex numbers
        a = (a * other.real()) - (b * other.imag()); //got to foil the numbers
        b = (a * other.imag()) + (b * other.real()); 
        Complex comp(a, b);
        return comp;
        
    }
	
	Complex operator / (Complex other) { //divide complex numbers
	    int aa = (a * other.real()) - (b * -1 * other.imag()); //multiply by conjugate of other
	    int bb = (a * -1 * other.imag()) + (b * other.real()); 
	    int aaa = (other.real() * other.real()) - (other.imag() * -1 * other.imag()); //foil the divisor; no need to multiply out the imaginary part bacause it cancels out
	    aa = aa/aaa;
	    bb = bb/aaa;
	    Complex comp(aa, bb);
	    return comp;
	}
	
	bool operator = (Complex other) { //equate complex numbers
	    if (a == other.real()){
	    if (b == other.imag()) {
	        return true;
	    }
	    }
	    return false;
	}
		
    operator const char* () { //conversion operator
        ostringstream imagine;
        imagine << a << " + " << b << "i";
        string theImaginary = imagine.str();
        return theImaginary.c_str();
    }
};

int main() {
    int repeat = 0; //repeat for convinence
    while (repeat == 0) {
        int a, b;
        cout << "Enter real part of complex number: " << endl; //create complex number
        cin >> a;
        cout << "Enter imaginary part of complex number: " << endl;
        cin >> b;
        Complex complex = Complex(a, b);
        int choice = 0;
        cout << "Enter 1 for the conjugate\nEnter 2 for the normal\nEnter 3 for the real part\nEnter 4 for the imaginary part\n"; //menu of choices
        cout << "Enter 5 for dot product\nEnter 6 for scalar product\nEnter 7 for the angle between\n";
        cout << "Enter 8 for addition\nEnter 9 for subtraction\nEnter 10 for multiplication\nEnter 11 for divison\nEnter 12 for equating\n";
        cin >> choice;
        
        if (choice == 1) {
            cout << complex.conjugate() << endl;
        }
        if (choice == 2) { 
            cout << complex.norm() << endl;
        }
        if (choice == 3) { 
            cout << complex.real() << endl;
        }
        if (choice == 4) { 
            cout << complex.imag() << endl;
        }
    
        if (choice == 5 || choice == 7 || choice == 8 || choice == 9 || choice == 10 || choice == 11 || choice == 12) { //for choices that need another complex number
            int a2, b2;
            cout << "Enter real part of another complex number: " << endl;
            cin >> a2;
            cout << "Enter imaginary part of another complex number: " << endl;
            cin >> b2;
            Complex complex2 = Complex(a2, b2); 
            
            if (choice == 5) { 
                cout << complex.dotProduct(complex2) << endl;
            }
            if (choice == 7) { 
                cout << complex.angleBetween(complex2) << endl;
            }
            if (choice == 8) {
                cout << (complex + complex2) << endl;
            }
            if (choice == 9) {
                cout << (complex - complex2) << endl;
            }
            if (choice == 10) {
                cout << (complex * complex2) << endl;
            }
            if (choice == 11) {
                cout << (complex / complex2) << endl;
            }
            if (choice == 12) {
                cout << "0 means that the 2 complex dont equate, 1 means that they do: " << (complex = complex2) << endl;
            }
        }
        
        if (choice == 6) { 
            int value;
            cout << "Enter a value you want to multiply the complex number by: " << endl;
            cin >> value;
            cout << complex.scalarProduct(value) << endl;
        }
        
        cout << "Enter 0 to try again or any other int to stop: \n";
        cin >> repeat;
    }
    return 0;
}






