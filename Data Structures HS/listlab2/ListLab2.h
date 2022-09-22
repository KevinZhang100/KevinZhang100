/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//ListLab2
//Author: Kevin Zhang
//Using Nodes
#include <iostream>
#include <string>
using namespace std;

#ifndef LISTLAB1_H
#define LISTLAB1_H

class ListNode {
	private:
		string value;
		ListNode* next;
	public:
		ListNode(string a, ListNode* b);
		ListNode* copyNode(ListNode* arg);
		ListNode* copyList(ListNode* arg);
		ListNode* rest(ListNode* h);
		string first(ListNode* head);
		string second(ListNode* head);
		ListNode* pointerToLast(ListNode* head);
		ListNode* copyOfLast(ListNode* head);
		ListNode* insertFirst(ListNode* head, string arg);
		ListNode* insertLast(ListNode* head, string arg);
		ListNode* remove(ListNode* head, int position);
		ListNode* insertMiddle(ListNode* head, string arg, int position);
		void setNext(ListNode* ptr);
		string getValue();
		ListNode* getNext();
};
string ListNode::getValue() { //get value
    return value;
}

ListNode *ListNode::getNext(){ //get next
    return next;
}

void ListNode::setNext(ListNode* ptr){ //set next
    next = ptr;
}

ListNode::ListNode(string a, ListNode* b) { //sets node
    value = a; 
	next = b;
}

ListNode* ListNode::copyNode(ListNode* arg)  { // returns a new node that is a copy of the argument node
	if(arg == NULL) { 
		return NULL; 
	}
    ListNode* copy = new ListNode(arg->value, arg->next);
    return copy;
}

ListNode* ListNode::copyList(ListNode* arg) {// returns a new list that is a copy of the original list.
	if(arg == NULL) { //make sure list is not empty
        return NULL;
    }
    
    ListNode* copy = arg->copyNode(arg);
    copy->setNext(copy->copyList(copy->next)); //next value is copy of next node
    return copy;
}

ListNode* ListNode::rest(ListNode* h) {//returns a new linked list containing copies of each node in the original list except the first node
    
    h = h->next;
    if(h == NULL) {
    	return NULL;
    }
    //returns values after the first node
    return h->copyList(h);
}

string ListNode::first(ListNode* head) { //get first value of node
	if(head == NULL) { 
		return "NULL";
	}
	return head->value;
}

string ListNode::second(ListNode* head) { //get nalue of 2nd node
	if(head == NULL) { 
		return "NULL";
	}
	ListNode* current = head; 
	current = current->next;
	return current->first(current); 
}

ListNode* ListNode::pointerToLast(ListNode* head) { //get location of last node
	if(head == NULL) { 
		return NULL;
	}
	
	if(head->next == NULL) { //stops recursion at the end
		return head;
	}
	
	return head->pointerToLast(head->next); 
}


ListNode* ListNode::copyOfLast(ListNode* head) { //returns copy of last node
    if(head == NULL) { 
		return NULL;
	}
	if(head->next == NULL) {
		return copyNode(head); //stops recursion, calls copynode for a copy
	}
	
	return head->copyOfLast(head->next); 
}

ListNode* ListNode::insertFirst(ListNode* head, string arg) { //returns a reference to a list whose first nodes value is specified by the argument
	ListNode* node = new ListNode(arg, NULL);
	node->next = head;
	return node;
}

ListNode* ListNode::insertLast(ListNode* head, string arg) {//returns a reference to a list whose last nodes value is specified by the argumen
	ListNode* end = new ListNode(arg, NULL);
	ListNode* temp = head->pointerToLast(head);
	temp->next = end;
	rest(head)->next = temp;
	return head;
}

ListNode* ListNode::insertMiddle(ListNode* head, string arg, int position) { // add a node to somewhere
    if (position == 0) {
        return insertFirst(head, arg); //if its first element call insert first method
    }
    
    if (position < 0) //doesnt change anything if you enter a negative
    {
        return head;
    }
    
    int count = 0;
    
    ListNode* temp1 = head; //find length of the list
    while (temp1 != NULL){
        temp1 = temp1->next;
        count++;
    }
    
    if (position-2 == count) //if last call insertlast method
    {
        return insertLast(head, arg);
    }
    
    ListNode* temp = head; //go through list until point to location of the position
    for(int i = 0; i < position-1; i++) {
        temp = temp->next;
        if (temp->next == NULL) { //if position is too big wont change anything
        return head;
        }
    }
    ListNode* insert = new ListNode(arg, temp->next); //adds the new node to the list
    temp->next = insert;
    return head;
    
}

ListNode* ListNode::remove(ListNode* head, int position) { //removes a node
    if (head == NULL) { //if there isnt anything to remove returns null
        return NULL;
    }
    if (position ==0){ //calls rest if removing head node
        return rest(head);
    }
    
    ListNode* temp = head; //go through list until point to location of the position
    for(int i = 0; i < position-1; i++) {
        temp = temp->next;
        if (temp->next == NULL) { //if position is too big wont change anything
        return head;
        }
    }
    
    ListNode* removed = temp->next; //points to the node at the specified position
    temp->next = removed->next; //sets everything after the removed node
    delete removed; //deletes node
    return head;
}

#endif
