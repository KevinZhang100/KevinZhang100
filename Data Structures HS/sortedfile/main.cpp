//SortedFile
//Author: Kevin Zhang
//sort a file
#include "SortedFile.h" 
#include <iostream>
#include<string>
#include <fstream>
#include<sstream> 
using namespace std;

int main()
{
    cout << "Enter the name of the file: ";
    string fileName;
    cin >> fileName;
    
    TreeNode* noded = NULL;
    string line;
    ifstream myfile (fileName);
    if (myfile.is_open()) {
    while ( getline (myfile, line) ) {
      istringstream ss(line); // gets the next word in a line
 
      string word; 
      while (ss >> word) { //gets next word

        if(noded == NULL) { 
          noded = new TreeNode(word, NULL, NULL);
        } else { 
          noded= noded->insert(noded, word);
        }
      }
    }
    string output = "result.txt";
        ofstream file;
        file.open (output);
        string tot = noded->sorted(noded);
        file << tot;
        file.close ();
        myfile.close ();
    }
    
    else { 
        cout << "Unable to open file";
    }
    
  return 0;
}
