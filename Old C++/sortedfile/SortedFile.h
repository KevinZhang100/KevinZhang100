//SortedFile
//Author: Kevin Zhang
//sort a file
#include <iostream>
#include <fstream>
#include<sstream> 
#include<string>
using namespace std;

#ifndef SORTEDFILE_H
#define SORTEDFILE_H

class TreeNode
{
    private:
    TreeNode* left;
    TreeNode* right;
    string value;
    stringstream ss;
    int count = 1;
    
    public:
    TreeNode(string a, TreeNode* b, TreeNode* c) {
        value = a;
        left = b;
        right = c;
        count = 1;
    } 

    TreeNode* insert(TreeNode* t, string s) {
        if (t == NULL) {
            TreeNode* newNode = new TreeNode(s, NULL, NULL);
            return newNode;
        }
    
        TreeNode* temp = t;
        TreeNode* newNode = new TreeNode(s, NULL, NULL);
        int last;
        while (temp!= NULL) {
            int x = s.compare(temp->value);
            
            if (x<0) {
                if (temp->left == NULL) {
                    goto loopDone;
                }
                temp = temp->left;
            }
                
            else if (x == 0) {
                temp->count = temp->count + 1;
                goto jumping;
            }
            
            else {
                if (temp->right == NULL) {
                    goto loopDone;
                }
                temp = temp->right;
            }
        }
    
        loopDone:
        last = s.compare(temp->value);
        if (last < 0) {
                temp->left = newNode;
                temp = temp->left;
        }
        
        else if (last == 0) {
            temp->count = temp->count + 1;
            temp = temp->left;
        }
        
        else {
            temp->right = newNode;
            temp = temp->right;
        }
        jumping:
        return t;
    }
    
    string sorted(TreeNode* t) {
        if (t == NULL) {
            return "";
        }
        
        return sorted(t->left) + t->value + ": " + to_string(t->count) + "\n" + sorted(t->right);
    }
        
};
#endif