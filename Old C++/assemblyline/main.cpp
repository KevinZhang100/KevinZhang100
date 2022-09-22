//AssemblyLine
//Author: Kevin Zhang
//simulate an assembly line with stacks
#include <iostream>
#include<string>
#include <fstream>
#include<sstream> 
using namespace std;

class AssemblyLine
{
    protected:
    int value;
    AssemblyLine* next;
    
    public:
    AssemblyLine* assemblyLineIn = NULL; 
    AssemblyLine* assemblyLineOut = NULL; 
    
    AssemblyLine (int a, AssemblyLine* b) { //constructor
        value = a;
        next = b;
    } 
    
    int isEmpty() { //determines if in is emprt or not
        if (assemblyLineIn == NULL){
            return 0;
        }
        return 1;
    }
    
    void makeLine (string s) { //makes a new assemblyLineIn
        string convert;
        int tot = 0;
        stringstream ss;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                ss << s[i];
            }
            
            if (s[i] == ' ' || i == s.length() - 1) {
                convert = ss.str ();
                assemblyLineIn = assemblyLineIn->addBack (stoi(convert), assemblyLineIn);
                ss.str ("");
                ss.clear();
            }
        }
    }
    
    string sorted () { //calls methods to do stuff and convert assemblyLineOut to a string
        robotArm();
        string total;
        while (assemblyLineOut->next != NULL) {
            total = total + to_string(assemblyLineOut->value) + " ";
            assemblyLineOut = assemblyLineOut->next;
        }
        total = total + to_string(assemblyLineOut->value);
        assemblyLineOut = NULL;
        return total;
    }
    
    void unloadRobot (){ //flips assemblyLineOut
        AssemblyLine* reversed = NULL;
        while (assemblyLineOut != NULL) {
            reversed = reversed->addHead(assemblyLineOut->value, reversed);
            assemblyLineOut = assemblyLineOut->next;
        }
        assemblyLineOut = reversed;
    }
    
    void robotArm (){ //adds nodes from assemblyLineIn stack to assemblyLineOut
        while (assemblyLineIn != NULL) {
            if (assemblyLineIn->next == NULL) { //when only one node is left in assemblyLineIn end list
                goto jumpElse;
            }
            if (assemblyLineIn->value < assemblyLineIn->next->value) { //adds nodes to assemblyLineOut as long as the next value is larger
                assemblyLineOut = assemblyLineOut->addBack(assemblyLineIn->value, assemblyLineOut);
                 assemblyLineIn = assemblyLineIn->removed(assemblyLineIn, 0);
                 
            }
            else {
                jumpElse:
                assemblyLineOut = assemblyLineOut->addBack(assemblyLineIn->value, assemblyLineOut); //adds last node
                assemblyLineIn = assemblyLineIn->removed(assemblyLineIn, 0);
                goto done;
            }
        }
        done:
        unloadRobot(); //calls to flip list
    }
    
    AssemblyLine *addBack (int s, AssemblyLine * head) { //add to the back of the list
        AssemblyLine *noded = new AssemblyLine(s, NULL);
        if (head == NULL) {
            head = noded;
            return head;
        }
        
        AssemblyLine *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = noded;
        return head;
    }
    
    AssemblyLine *addHead (int s, AssemblyLine * head) { //add to the head of the list
        AssemblyLine *noded = new AssemblyLine (s, head);
        head = noded;
        return head;
    }
    
    AssemblyLine *removed (AssemblyLine * head, int position) { //remove a node
        if (position == 0) {
            return rest (head);
        }
        
        AssemblyLine *temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        
        AssemblyLine *remover = temp->next;
        temp->next = remover->next;
        delete remover;
        return head;
    }
    
    AssemblyLine *rest (AssemblyLine * h) { //remove head node
        AssemblyLine *temp = h->next;
        h = temp;
        return h;
    }
};

class Disk: public AssemblyLine {
    protected:
    int value;
    Disk* next;
    
    public:
};

class Pyramid : public AssemblyLine{
    protected:
    int value;
    AssemblyLine* next;
    
    public:
};


int main()
{
    cout << "Enter the name of the file: ";
    string fileName;
    cin >> fileName;
    AssemblyLine *null = new AssemblyLine (69, NULL);
    ifstream myfile (fileName);
    string line;
    string tot = "Output: \n";
    int loop = 0;
    if (myfile.is_open ()) {
        while (getline (myfile, line)) {
            if (line[line.length () - 1] == '\n') {
                line.erase (line.length () - 1);
            }
            null-> makeLine(line);
            while (loop == 0) { //returns assemblyLineOut until assemblyLineIn is empty
                tot = tot + null->sorted() + "\n";
                if (null->isEmpty() == 0){
                    goto finished;
                }
            }
            finished:
            tot = tot + "--------" + "\n";
        }
        string output = "result.txt";
        ofstream file;
        file.open (output);
        file << tot;
        file.close ();
        myfile.close ();
    }
    
    else {
        cout << "Unable to open file";
    }
    
  return 0;
}




