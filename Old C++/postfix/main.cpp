//Postfix
//Author: Kevin Zhang
//does math with operators at the end with a stack
#include <iostream>
#include<string>
#include <algorithm>
#include <fstream>
#include <math.h>
#include<sstream>
using namespace std;

class Postfix
{
private:
  string value;
  Postfix *next;

public:
    string operators = "+-*/^!%";
  string numbers = "1234567890";

    Postfix (string a, Postfix * b)
  {				// constructs string and node
    value = a;
    next = b;
  }

  int Mathed (string s)
  {
    cout << "------------" << endl;
    string convert;
    int tot = 0;
    Postfix *str = NULL;	//creates a char list of the string
    stringstream ss;
    for (int i = 0; i < s.length (); i++)
      {
	if (s[i] != ' ') //since the numbers/operators are seperated by spaces constructs seperate strings between them
	  {
	    ss << s[i];
	  }

	if (s[i] == ' ' || i == s.length () - 1) //if the original string hits a space or the end
	  {
	    convert = ss.str ();
	    cout << convert << endl;
	    str = str->add (convert, str); //adds the smalller string to the node
	    ss.str ("");
	    ss.clear ();
	  }
      }
    Postfix *current = NULL;
    for (int i = 0; i < s.length (); i++)
      {
	if (str->value != "+" && str->value != "-" && str->value != "*"
	    && str->value != "/" && str->value != "!" && str->value != "^"
	    && str->value != "%") //if not any of the operators creates a new string that only has the numbers in reverse
	  {
	    current = current->addBack (str->value, current);
	  }

	if (str->value == "+")  //method for adding (other methods basically same idea)
	  {
	    Postfix *temp = current;
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
	    Postfix *temp = current;
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
	    Postfix *temp = current;

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
	    Postfix *temp = current;
	    if (temp->next != NULL)
	      {
		int tempInt = stoi (temp->next->value) / stoi (temp->value);
		current = current->removed (current, 0);
		current = current->removed (current, 0);
		current = current->addBack (to_string (tempInt), current);
	      }
	  }

	if (str->value == "^") //power
	  {
	      Postfix *temp = current;
	    if (temp->next != NULL)
	      {
	   int tempInt = pow(stoi(temp->next->value), stoi(temp->value));
		current = current->removed (current, 0);
		current = current->removed (current, 0);
		current = current->addBack (to_string (tempInt), current);
	      }
	  }

	if (str->value == "!") //factorial
	  {
	      Postfix *temp = current;
	        int tempInt = 1;
	   if (stoi(temp->value) != 0){
	    for (int z = 1; z <= stoi(temp->value); z++) {
	        tempInt = tempInt*z;
	    }
	   }
		current = current->removed (current, 0);
		current = current->addBack (to_string (tempInt), current);

	  }

	if (str->value == "%") //modulus
	  {
	    Postfix *temp = current;
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

  Postfix *add (string s, Postfix * head)
  {				//add method
    Postfix *noded = new Postfix (s, NULL);
    if (head == NULL)
      {
	head = noded;
	return head;
      }
    Postfix *temp = head;
    while (temp->next != NULL)
      {
	temp = temp->next;
      }
    temp->next = noded;

    return head;
  }

  Postfix *addBack (string s, Postfix * head)
  {				//add method with the last digit being the head
    Postfix *noded = new Postfix (s, head);
    head = noded;
    return head;
  }

  Postfix *removed (Postfix * head, int position)
  {				//removes a node
    if (position == 0)
      {
	return rest (head);
      }
    Postfix *temp = head;
    for (int i = 0; i < position - 1; i++)
      {
	temp = temp->next;
      }
    Postfix *remover = temp->next;
    temp->next = remover->next;
    delete remover;
    return head;
  }

  Postfix *rest (Postfix * h)
  {

    Postfix *temp = h->next;
    h = temp;
    return h;
  }
};

int
main ()
{
  cout << "Enter the name of the file: ";
  string fileName;
  cin >> fileName;
  Postfix *null = new Postfix ("n", NULL);
  ifstream myfile (fileName);
  string line;
  string tot;
  if (myfile.is_open ())
    {
      while (getline (myfile, line))
	{

	  if (line[line.length () - 1] == '\n')
	    {
	      line.erase (line.length () - 1);
	    }

	  int mathed = null->Mathed (line);
	  tot = tot + line + ": " + to_string (mathed) + "\n";
	  cout << mathed << endl;
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
