/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//WordCount
//Author: Kevin Zhang
//count how many times a word appears and display them in alphabetical order
#include <iostream>
#include <fstream>
#include<sstream> 
using namespace std;

class ListNode {
	private:
		string value;
		ListNode* next;
		int count;
		
	public:
		ListNode(string a, ListNode* b);
		
		//adds word List and if there is none, else add to number of times it already showed
		ListNode* add(ListNode* head, string word);
		
		
		string getValue() {
		    return value;
		}
		
		int getCount() { 
		    return count;
		}
		
		ListNode* getNext() {
		    return next;
		}
    
    void print(ListNode* head); //output
};

ListNode::ListNode(string a, ListNode* b) { // sets string and pointer and appear
	value = a; 
	next = b;
	count = 1;
}

ListNode* ListNode::add(ListNode* head, string word) {
  ListNode* node = head; 
  ListNode* prev = NULL; //stores the previous node
  
  int option = 0; 
  while(node != NULL) {
    int x = word.compare(node->getValue());
    if(x > 0) { // keep going down list since word is later
      prev = node;
      node = node->next;
    } 
    
    else if(x < 0) {
      option = 2;
      break;
     } 
    
    else { // same word
      node->count = node->getCount() + 1;
      option = 1;
      break;
    }
  }

  if(option == 0) { // add node to end
    ListNode* newNode = new ListNode(word, NULL);
    prev->next = newNode; 
  } 
  
  else if(option == 2) {
    if(prev != NULL) { // add new node in middle
      ListNode* newNode = new ListNode(word, prev->next);
      prev->next = newNode;
    } 
    
    else { //add new node in beginning
      ListNode* newNode = new ListNode(word, head);
      return newNode;
    }
  }

  return head;
}

void ListNode::print(ListNode* head) { // output 
  string output ="result.txt";
  ofstream myfile;
  myfile.open (output);
  while(head != NULL) { 
    myfile << head->getValue() << " " << head->count << "\n";
    head = head->getNext();
  }
  myfile.close();
}

int main () {
  cout << "Enter the name of the file: ";
  string fileName;
  cin >> fileName;

  ListNode* noded = NULL;

  string line;
  ifstream myfile (fileName);
  if (myfile.is_open()) {
    while ( getline (myfile, line) ) {
      istringstream ss(line); // gets the next word in a line
 
      string word; 
      while (ss >> word) { //gets next word

        if(noded == NULL) { 
          noded = new ListNode(word, NULL);
        } else { 
          noded= noded->add(noded, word);
        }
      }
    }

    if(noded->getNext() != NULL) { 

      noded->print(noded);
    }
    
    else {
      cout << "Empty List" << endl; 
    }

    myfile.close();
    
    }
    
    else { 
        cout << "Unable to open file";
    }
    
  return 0;
}