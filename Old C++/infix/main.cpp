//Infix
//Author: Kevin Zhang
//convert infix to postfix and then math
#include <iostream>
#include<string>
#include <algorithm>
#include <fstream>
#include <math.h>
#include<sstream>
using namespace std;

class Infix
{
private:
  string value;
  Infix *next;

public:
    string operators = "+-*/^!%";
  string numbers = "1234567890";

    Infix (string a, Infix * b) { // constructs string and node
    value = a;
    next = b;
  }
  
  int precedence(string s){ //lowest precedence for add/subtract, highest for multipy and divide, and medium for standard
     if (s == "+" || s == "-"){
         return 2;
     }
     if (s == "*" || s == "/"){
         return 0;
     }
     return 1;
  }
  
  string infixToPostfix(string s) { //converts from infix to postfix
      string convert;
      int tot = 0;
      Infix *str = NULL; //creates a list of the string
      stringstream ss;
      for (int i = 0; i < s.length(); i++) {
          if (s[i] != ' ') { //since the numbers/operators are seperated by spaces constructs seperate strings between them
              ss << s[i];
          }
          
          if (s[i] == ' ' || i == s.length() - 1) {//if the original string hits a space or the end
          convert = ss.str ();
	      str = str->add (convert, str); //adds the smalller string to the node
	      ss.str ("");
	      ss.clear();
          }
      }
      Infix * hold = NULL; //long hold a node
      Infix * fixed = NULL; //the fixed list
      int parenPrec = 0; //value that increases/decreases precedence based on parenthesis
      while (str != NULL){
          if (str->value == "+" || str->value == "-" || str->value == "*" || str->value == "/" || str->value == "(" || str->value == ")") {
              jumpParen:
              if (str->value == "("){ //increases precedence of next operator after a parenthesis is found
                  str = str->removed(str, 0); 
                  parenPrec = 3;
              }
              
              if (str->value == ")") { //end bracket
                  str = str->removed(str, 0);
                  if (hold!= NULL){
                      if (str->next == NULL){ //when an operator multiplies groups of parenthesis, uses hold and places the operator 
                      str = str->add(hold->value, str);
                      hold = NULL;
                      }
                      else{
                        str = str->insertMiddle(str, hold->value, 1);
                      hold = NULL;  
                      }
                  }
              }
              
              if (str->value == "+" || str->value == "-" || str->value == "*" || str->value == "/"){ 
                  string conversion = str->value; //converts the operators so that they are not looked at again by the program
                  if (conversion == "+") {
                      conversion = "q";
                  }
                  if (conversion == "-") {
                      conversion = "w";
                  }
                  if (conversion == "*") {
                      conversion = "e";
                  }
                  if (conversion == "/") {
                      conversion = "r";
                  }
                  if (str->next->value == "("){
                  str = str->removed(str, 1); 
                  parenPrec = -3; //if the next operator is an open parenthesis super low precedence
                  }
                  Infix* temp = str->next;
                  int pos = 2;
                  while (temp!= NULL){ 
                      int v1 = str->precedence(str->value)-parenPrec;
                      if (v1 > 2){ //super low precedence gets held until a closed parenthesis is found
                         hold = hold->add(conversion, hold);
                         str = str->removed(str, 0);
                         parenPrec = 0;
                         goto continuing;
                      }
                      int v2 = temp->precedence(temp->value);
                      if (v1<v2) { //higher precedence get swapped until the right position
                          str = str->insertMiddle(str, conversion, pos);
                          str = str->removed(str, 0);
                          parenPrec = 0;
                          goto continuing;
                      }
                      
                      if (temp->value == "+" || temp->value == "-" || temp->value == "*" || temp->value == "/"){
                          str = str->insertMiddle(str, conversion, pos+1);
                          str = str->removed(str, 0);
                          parenPrec = 0;
                          goto continuing;
                      }
                      
                      if (temp->value == ")") {
                          str = str->insertMiddle(str, conversion, pos);
                          str = str->removed(str, 0);
                          parenPrec = 0;
                          goto continuing;
                      }
                      pos++;
                      temp = temp->next;
                  }
                  str = str->add(conversion, str);
                  str = str->removed(str, 0); 
              }
              continuing:
              if (str->value == "(" || str->value == ")"){
                  goto jumpParen;
              }
              fixed = fixed->add(str->value, fixed);
              str = str->next;
          }
          
          else {
              fixed = fixed->add(str->value, fixed);
              if (str->next == NULL){
              goto endstr;
              }
              if (str->next!= NULL){
                  str = str->next;
              }
          }
      }
      endstr:
      string final = fixed->value + " ";
      while (fixed != NULL){
          if (fixed->next!= NULL){
              fixed = fixed->next;
          } 
          
          if (fixed->value == "q") {  //reconvert operators
              fixed->value = "+";
          }
          if (fixed->value == "w") {
              fixed->value = "-";
          }
          if (fixed->value == "e") {
              fixed->value = "*";
          }
          if (fixed->value == "r") {
              fixed->value = "/";
          }
          final = final + fixed->value + " ";
           if (fixed->next== NULL){
              goto jump2;
          }
      }
      jump2:
      return final;
  }

  int Mathed (string s)
  {
    cout << "------------" << endl;
    string convert;
    int tot = 0;
    Infix *str = NULL;	//creates a list of the string
    stringstream ss;
    for (int i = 0; i < s.length (); i++)
      {
	if (s[i] != ' ') //since the numbers/operators are seperated by spaces constructs seperate strings between them
	  {
	    ss << s[i];
	  }

	if (s[i] == ' ' || i == s.length() - 1) //if the original string hits a space or the end
	  {
	    convert = ss.str();
	    str = str->add (convert, str); //adds the smalller string to the node
	    ss.str ("");
	    ss.clear ();
	  }
      }
    Infix *current = NULL;
    for (int i = 0; i < s.length (); i++)
      {
	if (str->value != "+" && str->value != "-" && str->value != "*" && str->value != "/") //if not any of the operators creates a new string that only has the numbers in reverse
	  {
	    current = current->addBack (str->value, current);
	  }

	if (str->value == "+")  //method for adding (other methods basically same idea)
	  {
	    Infix *temp = current;
	    if (temp->next != NULL) //only does it if there are 2 nodes
	      {
		int tempInt = stoi (temp->value) + stoi (temp->next->value); //adds both values
		current = current->removed (current, 0); //removes the 2 original nodes
		current = current->removed (current, 0);
		current = current->addBack (to_string (tempInt), current); //creates a new node with the new value for future maths
	      }
	  }

	if (str->value == "-") //method for subtracting
	  {
	    Infix *temp = current;
	    if (temp->next != NULL)
	      {
		int tempInt = stoi (temp->next->value) - stoi (temp->value);
		current = current->removed (current, 0);
		current = current->removed (current, 0);
		current = current->addBack (to_string (tempInt), current);
	      }
	  }

	if (str->value == "*")//method for multiplying
	  {
	    Infix *temp = current;

	    if (temp->next != NULL)
	      {
		int tempInt = stoi (temp->value) * stoi (temp->next->value);
		current = current->removed (current, 0);
		current = current->removed (current, 0);
		current = current->addBack (to_string (tempInt), current);
	      }
	  }

	if (str->value == "/")//method for dividing
	  {
	    Infix *temp = current;
	    if (temp->next != NULL)
	      {
		int tempInt = stoi (temp->next->value) / stoi (temp->value);
		current = current->removed (current, 0);
		current = current->removed (current, 0);
		current = current->addBack (to_string (tempInt), current);
	      }
	  }

	if (str->value == "%") //modulus
	  {
	    Infix *temp = current;
	    if (temp->next != NULL)
	      {
		int tempInt = stoi (temp->next->value) % stoi (temp->value);
		current = current->removed (current, 0);
		current = current->removed (current, 0);
		current = current->addBack (to_string (tempInt), current);
	      }
	  }
	if (str->next == NULL) //if str reaches the end breaks out of loop
	  {
	    goto jump;
	  }
	str = str->next;
      }
  jump:
    tot = stoi (current->value); //there will only be one node left at the end (the final value)
    return tot;
  }

  Infix *add (string s, Infix * head)
  {				//add method
    Infix *noded = new Infix (s, NULL);
    if (head == NULL)
      {
	head = noded;
	return head;
      }
    Infix *temp = head;
    while (temp->next != NULL)
      {
	temp = temp->next;
      }
    temp->next = noded;

    return head;
  }

  Infix *addBack (string s, Infix * head)
  {				//add method with the last digit being the head
    Infix *noded = new Infix (s, head);
    head = noded;
    return head;
  }

  Infix *removed (Infix * head, int position)
  {				//removes a node
    if (position == 0)
      {
	return rest (head);
      }
    Infix *temp = head;
    for (int i = 0; i < position - 1; i++)
      {
	temp = temp->next;
      }
    Infix *remover = temp->next;
    temp->next = remover->next;
    delete remover;
    return head;
  }

  Infix *rest (Infix * h)
  {

    Infix *temp = h->next;
    h = temp;
    return h;
  }
  
  Infix* insertMiddle(Infix* head, string arg, int position) {
    //cout << position << head->next->value << endl;
    if (position == 0) {
        return addBack(arg, head);
    }
    
    int count = 0;
    
    Infix* temp1 = head; //find length of the list
    while (temp1 != NULL){
        temp1 = temp1->next;
        count++;
    }
    if (position >= count)
    {
        return add(arg, head);
    }
    
    Infix* temp = head;
    for(int i = 0; i < position-1; i++) {
        temp = temp->next;
        if (temp->next == NULL) { 
        return head;
        }
    }
    Infix* insert = new Infix(arg, temp->next); 
    temp->next = insert;
    return head;
  }

};

int main ()
{
  cout << "Enter the name of the file: ";
  string fileName;
  cin >> fileName;
  Infix *null = new Infix ("n", NULL);
  ifstream myfile (fileName);
  string line;
  string tot = "Infix -->  Postfix -->  Evaluate\n";
  if (myfile.is_open ())
    {
      while (getline (myfile, line))
	{

	  if (line[line.length () - 1] == '\n')
	    {
	      line.erase (line.length () - 1);
	    }
	  
	  string corrected = null-> infixToPostfix(line);
	  cout << corrected << endl;
	  int mathed = null->Mathed(corrected);
	  tot = tot + line + "     " + corrected + "     " + to_string (mathed) + "\n";
	}


      string output = "result.txt";
      ofstream file;
      file.open (output);
      file << tot;
      file.close ();
      myfile.close ();
    }

  else
    {
      cout << "Unable to open file";
    }
  return 0;
}


