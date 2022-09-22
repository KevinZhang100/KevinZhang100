//ListLab3
//Author: Kevin Zhang
//Make a Doubly Linked List
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
    string toStringNext(ListNode* head);
    string toStringPrev(ListNode* head);
};

ListNode::ListNode(string a, ListNode* b, ListNode* c) {
    value = a;
    next = b;
    prev = c;
} 

ListNode* ListNode::add(ListNode* head, string str){
    ListNode* node = new ListNode(str, head, NULL);
    if (head != NULL) {
        head->prev = node;
    }
    head = node;
    return head;
}

ListNode* ListNode::add(ListNode* head, string str, int pos){
       int count = 0;
    
    ListNode* temp1 = head; //find length of the list
    while (temp1 != NULL){
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

ListNode* ListNode::last(ListNode* head, string str) {
    ListNode* node = new ListNode(str, NULL, NULL);
    ListNode* last = head;
    while (last->next != NULL){
        last = last->next;
    }
    last->next = node;
    node->prev = last;
    return head;
}


ListNode* ListNode::removed(ListNode* head) {
    if(head != NULL) {
      ListNode* temp = head;
      head = head->next;
      temp = NULL;
      if(head != NULL) {
        head->prev = NULL;
      }
    }
    return head;
}

ListNode* ListNode::removed(ListNode* head, int pos){
   if (head == NULL) {
        return NULL;
   }
   
   ListNode* temp = head;
    for(int i = 0; i < pos-1; i++) {
      if(temp != NULL) {
        temp = temp->next;
      }
    }
    
    if(temp != NULL && temp->next != NULL) {
        ListNode* del = temp->next;
        if (del->next != NULL) {
        del->next->prev = del->prev;
        del->prev->next = del->next;
        }
        
        if (del->next == NULL) {
            temp->next = NULL;
        }
        
        delete del; 
    }
        return head;
}

 
string ListNode::toStringNext(ListNode* head) {
	ostringstream tot; 
	tot << head->value;
	ListNode* temp = head;
	while(temp->next != NULL) {
	    temp = temp->next;
	    tot << " " << temp->value;
	}
	
	string s = tot.str();
	return s;
}

string ListNode::toStringPrev(ListNode* head) {
	ostringstream tot; 
	ListNode* temp = head;
	while(temp->next != NULL) {
	    temp = temp->next;
	}
	
	tot << temp->value;
    while(temp->prev != NULL) {
	    temp = temp->prev;
	    tot << " " << temp->value;
	}
	string s = tot.str();
	return s;
}

#endif