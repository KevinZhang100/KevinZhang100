/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//ListLab4
//Author: Kevin Zhang
//Make a Circular Doubly Linked List
#include <iostream>
#include "ListLab4.h"
using namespace std;

int main()
{
     int loop = 0; 
     int printpos;
     string temp;
     int choice = 0;
     cout << "Enter head of list: "<< endl;
     cin>>temp;
     ListNode* head = new ListNode(temp, NULL, NULL);
     head = head ->setHead(head);
     
    while (loop == 0) {
        cout << "Enter a string: "<< endl;
        cin >> temp;
        cout << "Enter the position of the node, or 0 for it to be added at the start: " <<endl;
        cin >> choice;
        if (choice == 0) {
            head = head -> add(head, temp);
        }
        
        if (choice > 0) {
            head = head -> add(head, temp, choice);
        }
        
        if (choice < 0) {
            cout << "not valid" << endl;
        }
        cout << "Enter 0 to continue adding nodes or 1 to stop: " << endl;
        cin >> loop;
    }
    
    cout << "what position do you want to start printing?"<< endl;
    cin >> printpos;
    cout << "Your list forward at given position is: " << endl;
    cout << head->toStringNext(head, printpos) << endl;
    cout << "Your list backwards at given position is: " << endl;
    cout << head->toStringPrev(head, printpos) << endl;
    loop = 0;
    
    while (loop == 0) {
        cout << "Enter the position of the node you want to remove, or 0 to remove head: " <<endl;
        cin >> choice;
        if (choice == 0) {
            head = head -> removed(head);
        }
        
        if (choice > 0) {
            head = head -> removed(head, choice);
        }
        
        if (choice < 0) {
            cout << "not valid" << endl;
        }
        cout << "Enter 0 to continue removing nodes or 1 to stop: " << endl;
        cin >> loop;
    }
    
    cout << "Your list forward at given position is: " << endl;
    cout << head->toStringNext(head, printpos) << endl;
    cout << "Your list backwards at given position is: " << endl;
    cout << head->toStringPrev(head, printpos) << endl;
 	return 0;
}