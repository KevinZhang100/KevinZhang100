//WordTree
//Author: Kevin Zhang
//stores all of the words using a Trie
#include <iostream>
#include <fstream>
#include<sstream> 
#include<string>
using namespace std;

#ifndef WORDTREE_H
#define WORDTREE_H

class WordNode
{
    private:
    char value;
    WordNode* children[26];
    bool endOfWord;
    
    public:
    WordNode() {
        endOfWord = false;
        for (int i = 0; i < 26; i++) {
            this->children[i] = nullptr;
        }
    }
    
    WordNode* buildTree(ifstream &file, int &count) {
        string line;
        string text = "";
        if (file.is_open()) {
            while (getline(file, line)) {
                text = text + line + " ";
            }
            file.close();
        }

        WordNode *root = new WordNode();
        stringstream ss(text);
        string word;

        while (ss >> word) {
            if (word != "") {
                count = count + word.length();
                root->insert(root, word);
            }
        }
        
        return root;
    }
    
    void insert(WordNode* w, string s) {
        for(int i = 0; i < s.length(); i++) {
            int index = s[i]-'a';
            if (w->children[index] == NULL) {
                w->children[index] = new WordNode();
            }
            w = w->children[index]; 
        }
        w->endOfWord = true;
    }
    
    void traverse(string prefix, WordNode* w, ofstream &file) {
        for(int i = 0; i < 26; i++) {
            if(w->children[i] != NULL) {
                string combined = prefix+char(i + 'a');
                if(w->children[i]->endOfWord == true) { 
                    file << combined << endl;
                }
                w->traverse(combined, w->children[i], file);
            }
        }
    }
    
    int countNodes(WordNode* w) {
        int tot = 1;
        for (int i = 0; i < 26; i++)  { 
            if (w->children[i] != NULL) {
                tot = tot + countNodes(w->children[i]);
            }
        }
        return tot;
    }
};
#endif