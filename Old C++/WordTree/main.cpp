//WordTree
//Author: Kevin Zhang
//stores all of the words using a Trie
#include "WordTree.h" 
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
    
    WordNode* root = NULL;
    string line;
    ifstream myfile (fileName);
    if (myfile.is_open()) {
        int count = 0;
        root = root->buildTree(myfile, count);
        int treeCount = root->countNodes(root);
        string output = "result.txt";
        ofstream file;
        file.open (output);
        root->traverse("", root, file);
        cout << "List total: " << count << '\n';
        cout << "Tree total: " << treeCount << '\n';
        cout << "Savings: " << (double)(count - treeCount) / (double)count * 100 << '\n';
        file.close();
    }
    
    else { 
        cout << "Unable to open file";
    }
    
  return 0;
}
