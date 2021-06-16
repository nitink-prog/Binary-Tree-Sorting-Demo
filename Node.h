//
//  Node.h
//  Trees
//
//  Created by Nitin K on 5/2/19.
//  Copyright © 2019 CSCI 373. All rights reserved.
//

#ifndef Node_h
#define Node_h
#include <stdio.h>
#include <iostream>
using namespace std;

class Node
// Simple Node, containing pointers to left and right, and var for integer
{
public:
    Node()
    { *left = NULL; *right = NULL; }
    
    Node(int data, Node *Lptr = NULL, Node *Rptr = NULL)
    { info = data; left = Lptr; right = Rptr; }
    
    int info;
    Node *left, *right;
};

class ANode
// Node for AVLTree, adds Height var
{
public:
    ANode()
    { *left = NULL; *right = NULL; }
    
    ANode(int data, ANode *Lptr = NULL, ANode *Rptr = NULL)
    { info = data; left = Lptr; right = Rptr; }
    
    int info; int height;
    ANode *left, *right;
};
#endif /* Node_h */
