//TreeLab
//Author: Kevin Zhang
//make and do stuff with trees
#include <iostream>
#include <fstream>
#include<sstream> 
#include<string>
using namespace std;

#ifndef TREELAB_H
#define TREELAB_H

class TreeNode
{
    private:
    TreeNode* left;
    TreeNode* right;
    char value;
    stringstream ss;
    
    public:
    TreeNode(char a, TreeNode* b, TreeNode* c);
	TreeNode* buildTree(string s); //takes a string parameter and builds a BST where each letter is a node
	TreeNode* insert(TreeNode* t, char s); //inserts a node containing the character into the tree
	string display(TreeNode* t, int level);
	string preorderTraverse(TreeNode* t);
	string inorderTraverse(TreeNode* t);
	string postorderTraverse(TreeNode* t);
	int countNodes(TreeNode* t);
	int countLeaves(TreeNode* t);
	int countGrandParents(TreeNode* t);
	int countOnlyChildren(TreeNode* t);
	int height(TreeNode* t); //returns the max of the heights to the left and the heights to the right ;
	int longestPath(TreeNode* t); //return the max of the sum of the heights to the left and the heights to the right
	char min(TreeNode* t);
	char max(TreeNode* t);
	string displayCurrentLevel(TreeNode* t, int level);
	string displayLevelOrder(TreeNode* t);
	char maxed(char m1, char m2);
	char mined(char m1, char m2);
	//this class must contain the character representing the current letter as well as pointers to the left and right
	//children
	//you may have TreeNode objects or TreeNode pointers as parameters/returns based upon how you set up your code
};  

TreeNode::TreeNode(char a, TreeNode* b, TreeNode* c) { //construtor
    value = a;
    left = b;
    right = c;
} 

TreeNode* TreeNode::buildTree(string s) { //makes the tree
    TreeNode* tree = NULL;
    for (int i = 1; i < s.length(); i++) {
        char c = s[i];
        tree = tree->insert(tree, c);
    }
    return tree;
    
}

TreeNode* TreeNode::insert(TreeNode* t, char s) { //adds a node to the tree
    if (t == NULL) {
        TreeNode* newNode = new TreeNode(s, NULL, NULL);
        return newNode;
    }
    
    TreeNode* temp = t;
    TreeNode* newNode = new TreeNode(s, NULL, NULL);
    while (temp!= NULL) {
        if (s <= temp->value) {
            if (temp->left == NULL) {
                goto loopDone;
            }
            temp = temp->left;
        }
        else {
            if (temp->right == NULL) {
                goto loopDone;
            }
            temp = temp->right;
        }
    }
    
    loopDone:
    if (s <= temp->value) {
            temp->left = newNode;
            temp = temp->left;
    }
    
    else {
        temp->right = newNode;
        temp = temp->right;
    }
    return t;
}

string TreeNode::display(TreeNode* t, int level) { //displays the tree like art
    if (t == NULL) {
        return "";
    }
    string space;
    for (int i = 0; i < level; ++i) {
        space += "    ";
    }
    return display(t->right, level + 1) + space + string(1, t->value) + "\n" + display(t->left, level + 1);
}

string TreeNode::preorderTraverse(TreeNode* t) { //does preorder transveral
    if (t == NULL) {
        return "";
    }
    return string(1, t->value) + preorderTraverse(t->left) + preorderTraverse(t->right);
}

string TreeNode::inorderTraverse(TreeNode* t) { //does inorder transveral
    if (t == NULL) {
        return "";
    }
    return inorderTraverse(t->left) + string(1, t->value) + inorderTraverse(t->right);
}

string TreeNode::postorderTraverse(TreeNode* t) { //does postorder transveral
    if (t == NULL) {
            return "";
    }
    return postorderTraverse(t->left) + postorderTraverse(t->right) + string(1, t->value);
}

int TreeNode::countNodes(TreeNode *t) { //gets number of nodes in the tree
    if (t == NULL) {
        return 0;
    }
    int consta = 1;
    return consta + countNodes(t->left) + countNodes(t->right);
}
    
int TreeNode::countLeaves(TreeNode* t) { //counts number of leaves
    if(t == NULL) {
        return 0;
    }
    if(t->left == NULL && t->right == NULL) {
        return 1;       
    }
    else {
        return countLeaves(t->left)+ countLeaves(t->right);
    }
}

int TreeNode::countOnlyChildren(TreeNode *t) { //counts number of children in a tree
    if (t == NULL) {
        return 0;
    }

    if (t->left == NULL ^ t->right == NULL) { //use xor operator in case both case are true
        return 1 + countOnlyChildren(t->left) + countOnlyChildren(t->right);
    }
        
    else {
        return countOnlyChildren(t->left) + countOnlyChildren(t->right);
    }
}

int TreeNode::countGrandParents(TreeNode* t) { //count number of granparent leaves
    if (t == NULL) {
        return 0;
    }
    int grand = 0;
    
    if (t->left != NULL) { // checks for grandparents in left node
        if (t->left->left != NULL){
            grand = 1;
        }
        
        if (t->left->right != NULL) {
            grand= 1;
        }
    }

    if (t->right != NULL) { // checks for grandparents in right node
        if (t->right->left != NULL) {
            grand = 1;
        }
        if (t->right->right != NULL) {
            grand = 1;    
        }
    }
    return grand + countGrandParents(t->left) + countGrandParents(t->right);
}

int TreeNode::longestPath(TreeNode* t) { //find longest path in tree
    if (t == NULL) {
            return 0;
    }
    int totLength = height(t->left) + height(t->right);
    return maxed(totLength+ 1, maxed(longestPath(t->left), longestPath(t->right)));
}

char TreeNode::maxed(char m1, char m2) {
    return (m1 > m2) ? m1 : m2;
}
    
char TreeNode::mined(char m1, char m2) {
    return (m1 < m2) ? m1 : m2;
}

char TreeNode::min(TreeNode* t) { //min node
    TreeNode* current = t;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->value;
}

char TreeNode::max(TreeNode* t) { //max node
    TreeNode* current = t;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->value;
}

string TreeNode::displayLevelOrder(TreeNode* t) { //does level order transveral
    stringstream sss;
    int h = height(t);
    for (int i = 0; i <= h; i++) {
        sss<<displayCurrentLevel(t, i);
        ss.str("");
        ss.clear();
    }
    string total = sss.str();
    return total;
}

int TreeNode::height(TreeNode* t) { //height of the tree
    if (t == NULL)
        return -1;
    else {
        int lheight = height(t->left);
        int rheight = height(t->right);
 
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

string TreeNode::displayCurrentLevel(TreeNode* t, int level) { //displays current level of tree
    if (t == NULL) {
        return "";
    }
    
    if (level == 0) {
        ss << t->value;
    }
    else if (level > 0) {
        displayCurrentLevel(t->left, level - 1);
        displayCurrentLevel(t->right, level - 1);
    }
    
    string total = ss.str();
    return total;
}
#endif