//BigMath
//Author: Kevin Zhang
//Add or subtract 2 big numbers
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

#ifndef BIGMATH_H
#define BIGMATH_H

class BigMath {
    private:
    BigMath* next;
    int number;
    int lengthed;
    
    public:
    BigMath* operator + (BigMath other);
    BigMath* operator - (BigMath other);
    BigMath(int n, BigMath* numb);
    BigMath* getNext();
    int getNum();
    void setNext(BigMath* n);
    string toString();
    void setLength(int n);
    BigMath toNum(string s);
};

    
BigMath::BigMath(int n, BigMath* numb) {
        number = n;
        next = numb;
    }

BigMath* BigMath::getNext() {
        return next;
    }

int BigMath::getNum() {
        return number;
    }

void BigMath::setNext(BigMath* n) {
    next = n;
}

void BigMath:: setLength(int n) {
    lengthed = n;
}

 BigMath* BigMath::operator + (BigMath other) { // add
        BigMath* A = this;
        BigMath* B = &other;
        
        int aLength = A->toString().length();
		int bLength = B->toString().length(); // A will be larger in length or the same length as B
		
		if(aLength < bLength) { // if true swap
        A = &other;
        B = this;
		}
		
        int carry = 0;
        int sum = B->getNum() + A->getNum(); //sum 
        BigMath* added = new BigMath(sum%10, NULL);
        
        int re = sum/10; //if > 10 add one to the next sum
        if (re == 1) {
            carry = 1;
        }
		
		while(A->next != NULL && B->next != NULL) { //get sums of nodes until either a or b is finished
		    B = B->next;
		    A = A->next; 
		    
		    sum = B->number + A->number + carry;
		    BigMath* temp = new BigMath(sum%10, NULL);
		    
		    BigMath* ptr = added; //traverse to end of list
		    while (ptr->next != NULL) { 
		        ptr = ptr->next;
		    }
		    ptr->next = temp;
		    
		    re = sum/10;
		    if (re == 1) {
		       carry = 1;
		    }
		}
		
		if (A-> next != NULL && B->next == NULL) { //if one of the numbers has more digits keep going
		    while (A->next != NULL) {
		        A = A->next;
		        sum = A->number + carry;
		        BigMath* temp = new BigMath(sum%10, NULL);
		        
		        BigMath* ptr = added; //traverse to end of list
		        while (ptr->next != NULL) { 
		            ptr = ptr->next;
		        }
		        
		        ptr->next = temp;
		        re = sum/10;
		        if (re == 1){ 
		        carry = 1;
		        }
		        
		    }
		}
		
		
		if (A-> next == NULL && B->next == NULL) { //if both numbers are equal in length but they add together (ie 999+999 = 1998) add a 1 
		    if (carry == 1){
		        BigMath* temp = new BigMath(1, NULL);
		        BigMath* ptr = added; //traverse to end of list
		        while (ptr->next != NULL) { 
		            ptr = ptr->next;
		        }
		        ptr->next = temp;
		    }
		}
		
		return added;
}
 
 BigMath* BigMath::operator - (BigMath other){
     BigMath* A = this;
        BigMath* B = &other;
        
        int aLength = A->toString().length();
		int bLength = B->toString().length(); // A will be larger in length or the same length as B
		
		if(aLength < bLength) { // if true swap
        A = &other;
        B = this;
		}
		
		int carry = 0;
        int sub = A->getNum() - B->getNum(); //subtract the numbers
        if (sub < 0) {
		       carry = 1;
		       sub = sub+10; //if its negative add 10 and carry a one
		    }
        BigMath* subed = new BigMath(abs(sub), NULL);
        
		
		while(A->next != NULL && B->next != NULL) {
		    B = B->next;
		    A = A->next; 
		    
		    sub = A->number - B->number - carry;
		    if (sub < 0) {
		       carry = 1;
		       sub = sub+10;
		    }
		    BigMath* temp = new BigMath(abs(sub), NULL);
		    BigMath* ptr = subed; //traverse to end of list
		    while (ptr->next != NULL) { 
		        ptr = ptr->next;
		    }
		    ptr->next = temp;
		    
		}
		
		
			if (A-> next != NULL && B->next == NULL) {
		    while (A->next != NULL) {
		        A = A->next;
		        sub = A->number - carry;
		        BigMath* temp = new BigMath(abs(sub), NULL);
		        
		        BigMath* ptr = subed; //traverse to end of list
		        while (ptr->next != NULL) { 
		            ptr = ptr->next;
		        }
		        
		        ptr->next = temp;
		        if (sub < 0) {
		       carry = 1;
		    }
		    
		    }
		}
		
		
	return subed;	
 }

string BigMath::toString() {
	ostringstream totNum; 
	BigMath* temp = this;
	totNum << temp->getNum();
	while(temp->next != NULL) {
	    temp = temp->next;
	    totNum << temp->getNum();
	}
    
	string s = totNum.str();
	ostringstream reverse;
	for (int i = s.length()-1; i>=0; i--) {
	   reverse << s[i]; 
	}
	string ss = reverse.str();
	return ss;
}

BigMath BigMath::toNum(string s) {
    int length = s.length()-1;
    string ss(1, s[length]);
    int first = stoi(ss);
    
	if (s.length() == 1) {
	    BigMath other = BigMath(first, NULL);
	    return other;
	}
	
	BigMath* temp = new BigMath(s[0]-48, NULL);

	for(int i = 1; i < length; i++) { //goes in reverse
	    string sTemp(1, s[i]);
	    int num = stoi(sTemp);
	    BigMath* temp2 = new BigMath(num, NULL);
    	temp2->next = temp;
        temp = temp2;
	}
	
	BigMath other = BigMath(first, temp);
	return other;
}
#endif