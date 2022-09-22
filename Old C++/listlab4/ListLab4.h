//ListLab4
//Author: Kevin Zhang
//Make a Circular Doubly Linked List
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#ifndef LISTLAB4_H
#define LISTLAB4_H

class ListNode {
    private:
    string value;
    ListNode* next;
    ListNode* prev;
    
    public:
    ListNode(string a, ListNode* b, ListNode* c);
    ListNode* add(ListNode* head, string str);
    ListNode* add(ListNode* head, string str, int pos);
    ListNode* last(ListNode* head, string str);
    ListNode* removed(ListNode* head);
    ListNode* removed(ListNode* head, int pos);
    ListNode* setHead(ListNode* head);
    string toStringNext(ListNode* head, int pos);
    string toStringPrev(ListNode* head, int position);
    string getValue(){
        return value;
    }
    int getLength(ListNode* head) {
        int count = 1;
    
    ListNode* temp1 = head; //find length of the List
    while (temp1->next != head){
        temp1 = temp1->next;
        count++;
    }
    return count;
    }
};

ListNode::ListNode(string a, ListNode* b, ListNode* c) {
    value = a;
    next = b;
    prev = c;
} 

ListNode* ListNode::setHead(ListNode* head){ //creates a circularly linked list after head is made
    head->prev = head;
    head->next = head;
    return head;
}

ListNode* ListNode::add(ListNode* head, string str){ //adds head in circularly linked list
    ListNode* node = new ListNode(str, head, NULL);
    if (head != NULL) {
        head->prev = node;
    }
    ListNode* temp1 = head;  //finds the end of the list to connect the end of the list with the new head of the list
    while (temp1->next != head){
        temp1 = temp1->next;
    }
    temp1->next = node;
    node->prev = temp1;
    node->next = head;
    head = node;
    return head;
}

ListNode* ListNode::add(ListNode* head, string str, int pos){ //adds nodes in the middle of the list, same as standard doubly linked list
       int count = 1;
    
    ListNode* temp1 = head; //find length of the List
    if (temp1->next != head){
        temp1 = temp1->next;
        count++;
    }
    while (temp1 != head){
        temp1 = temp1->next;
        count++;
    }
    if (pos == count) //if last call insertlast method
    {
        ListNode* node = last(head, str);
        return node;
    }
    
    if (pos > count) {
        return head;
    }
    
    ListNode* node = new ListNode(str, NULL, NULL);
     ListNode* prevNode = head; //go through list until point to location of the position
    for(int i = 0; i < pos-1; i++) {
        prevNode = prevNode->next;
    }
    
    node->next = prevNode -> next;
    prevNode->next = node;
    node->prev = prevNode;
    node ->next->prev = node;
    return head;
}

ListNode* ListNode::last(ListNode* head, string str) { //adds last node and connects it with the head
    ListNode* node = new ListNode(str, NULL, NULL);
    ListNode* last = head;
    while (last->next != head){
        last = last->next;
    }
    last->next = node;
    node->prev = last;
    node->next = head;
    head->prev = node;
    return head; 
}


ListNode* ListNode::removed(ListNode* head) { //remove the head, and connects the new head with the tail
    if(head != NULL) {
        
    ListNode* temp1 = head;
    while (temp1->next != head){
        temp1 = temp1->next;
    }
    
      ListNode* temp = head;
      
      if(head->next != head) {
        head = head->next;
        temp1->next = head;  
        head->prev = temp1;
      }
      temp = NULL;
    }
    return head;
}

ListNode* ListNode::removed(ListNode* head, int pos){ //remove from middle/end
   if (head == NULL) {
        return NULL;
   }
   
   ListNode* temp = head;
    for(int i = 0; i < pos-1; i++) {
        temp = temp->next;
    }
    
        ListNode* del = temp->next;
        if (del->next != head) {
        del->next->prev = del->prev;
        del->prev->next = del->next;
        }
        
        if (del->next == head) {
            temp->next = head;
            head->prev = temp;
        }
        
        delete del; 
        
        return head;
}

 
string ListNode::toStringNext(ListNode* head, int pos) { //prints 3 times to demonstrate list is circular
	ostringstream tot; 
	ListNode* temp = head;
	int length = getLength(head);
	
	for (int i = 0; i < pos; i++){
	    temp = temp->next;
	}
	
	tot << temp->value;
	
	for(int i = 0; i < length-1; i++) {
	    temp = temp->next;
	    tot << " " << temp->value;
	}
	string s = tot.str();
	return s;
}

string ListNode::toStringPrev(ListNode* head, int pos) { //prints 3 times to demonstrate list is circular
	ostringstream tot;
	ListNode* temp = head;
	int length = getLength(head);
	while(temp->next != head) {
	    temp = temp->next;
	}
		for (int i = 0; i < pos; i++){
	    temp = temp->next;
	}
	tot << temp->value;
	for(int i = 0; i < length-1; i++) {
	    temp = temp->prev;
	    tot << " " << temp->value;
	}
	string s = tot.str();
	return s;
}

#endif