//DuckDuckGoose
//Author: Kevin Zhang
//Make a Josephus Problem
#include <iostream>
#include "DuckDuckGoose.h"
#include <fstream>
#include<sstream> 
#include<string>
using namespace std;

int main()
{
    cout << "Enter the name of the file: ";
    string fileName;
    cin >> fileName;

  int numPlayers;
  int numCycles;
  int trial = 1;
  string line;
  int alt = 0;
  ifstream myfile (fileName);
  ListNode* list = NULL;
  string tot = "Winners with the first player starting at position 1: \n";
  int length = 0;
  if (myfile.is_open()) {
    while ( getline (myfile, line) ) {
        
        if (alt == 0) {
            int numPlayers = stoi(line);
            list = list->linkList(numPlayers);
            alt = 1;
        }
        else if (alt == 1) {
            int numCycles = stoi(line);
            string winner = list->getWinner(list, numCycles);
            tot = tot + to_string(trial)+ ": " + winner + "\n";
            trial++;

            alt = 0;
        }
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
