//ParenthesesMatch
//Author: Kevin Zhang
//checks to see whether or not the parentheses for each line match
#include <iostream>
#include<string>
#include <fstream>
#include<sstream> 
using namespace std;

class ParenMatch
{
    private: 
    char value;
    ParenMatch* next;
    
    public:
    string left = "([{<";
    string right = ")]}>";

    bool checkParen(string s) { //checks the parentheses
        char convert = s[0];
        ParenMatch* str = new ParenMatch(convert, NULL); //creates a char list of the string
        for (int i = 1; i < s.length(); i++) {
            convert = s[i];
            str = str->add(convert, str);
        }
        
        int count = 0; //position of last value
        int count2 = 0;//position of first value
        int index = 0;//the position of the char in either left or right
         for (int i = 0; i < s.length(); i++) {
             count =0;
             count2 = 0;
             if (str->next != NULL) { //once end of list is reached ends
             for (int j = 0; j < 4; j++) { //4 possible brackets, so goes through each one
                 index = j;
                 if (str->value == right[index]) { //cant have right bracket fist
                     return false;
                 }
                 if (str->value == left[index]) { //left bracket cases
                     ParenMatch* temp = str; //creates a list that points to str, with the left bracket as the head node, goes through that list
                     while (temp->next != NULL) {
                         temp = temp->next;
                         count++;
                         if (temp->value == '(' || '[' || '{' || '<') {//in the case that the next node is another left, prioritize that node first(remove the inside brackets first)
                             for (int k = 0; k < 4; k++){
                                 if (temp->value == left[k]){
                                     index = k;
                                     count2 = count;
                                 }
                             }
                         }
                         if (right.find(temp->value) != string::npos){//only happens if a bracket is found
                         if (temp->value == right[index]) {//if right bracket happens to be the counterpart removes both the left and right
                             str = str->removed(str, (count));
                             str = str->removed(str, count2);
                             i--;//starting position is the same, so dont i++
                             goto jump;//jumps the false and str->next
                         }
                         else{//if the right bracket is a different type of bracket return false
                             return false;
                         }
                         }
                     }
                     return false; //if there is no bracket return false
                 }
             }
             str = str->next;
             jump: int p = 0;
             }
         }
         
        for (int w = 0; w < 4; w++) { //checks to see if the last char is a bracket or not
                 index = w;
                 if (str->value == right[index]|| str->value == left[index]) {
                     return false;
                 }
        }
        return true;
    }
    
    ParenMatch(char a, ParenMatch* b) { // constructs string and node
	value = a; 
	next = b;
    }
    
    ParenMatch* add(char s, ParenMatch* head){ //add method
        ParenMatch* noded = new ParenMatch(s, NULL);
        if (head == NULL) {
            head = noded;
            return head;
        }
        ParenMatch* temp = head;
        while (temp->next != NULL) { 
            temp = temp->next;
        }
        temp->next = noded;
        
        return head;
    }
   
   ParenMatch* removed(ParenMatch* head, int position) { //removes a node
    if (position ==0){
        return rest(head);
    }
    ParenMatch* temp = head;
    for(int i = 0; i < position-1; i++) {
        temp = temp->next;
    }
    ParenMatch* remover = temp->next;
    temp->next = remover->next;
    delete remover;
    return head;
}

ParenMatch* rest(ParenMatch* h) {
    
    ParenMatch* temp = h->next;
    h = temp;
    return h;
}
};

int main()
{
cout << "Enter the name of the file: ";
string fileName;
cin >> fileName;
ParenMatch* null = new ParenMatch('n', NULL);
ifstream myfile (fileName);
string line;
int lined = 1;
string tot;
if (myfile.is_open()) {
    while ( getline (myfile, line) ) {
    bool checked = null->checkParen(line);
    if (checked) {
        tot = tot + to_string(lined) + ": " + "good!" + "\n";
    }
    else {
        tot = tot + to_string(lined) + ": " +"BAD" + "\n";
    }
    lined++;
    }
    
    
string output = "result.txt";
    ofstream file;
    file.open(output);
    file <<tot;
    file.close();
    myfile.close();
}
    
    else { 
        cout << "Unable to open file";
    }
    return 0;
}



