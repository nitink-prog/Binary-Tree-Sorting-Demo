//
//  BSTree.cpp
//  Trees
//
//  Created by Nitin K on 5/2/19.
//  Copyright © 2019 CSCI 373. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Node.h"
using namespace std;

class BSTree
// Type of Tree where there are 0, 1, or 2 children per Node...
// ...It has built-in sorting, where the median is the root Node...
// ...Maintains fullness/completeness during insertion //
{
public:
    BSTree()
    { root = NULL; }
    
    ~BSTree()
    {
        cout << "BSTree Warning: Destructor called." << endl;
        destroyTree(*&root);
        cout << "----------------" << endl;
    }
    
    // ***** INSERTION ***** //
    void insert(int data)
    {
        insert(data, root);
    }
    
    void autoFill(int amount)   // Function to automatically fill the tree...
    {                           // ...with random numbers //
        for(int i = 0; i < amount; i++)
            insert(rand()%1000);
    }
    
    // ***** DELETION ***** //
    void deleteHalf()
    {
        int halfsize = numberOfNodes(root) / 2;
        
        while (numberOfNodes(root) > halfsize)
            findAndDeleteMerging(rand()%1000);
    }
    
    void deleteMerging(Node *node) // Using a merging alogrithim
    {
        Node *tmp = node;        //passes the value to a pointer Node *node
        if (node != NULL)
        {
            if (!node->right)           // no children
                node = node->left;
            
            else if (node->left == NULL) // one child node
                node = node->right;
            
            else                        //contains both children
            {
                tmp = node->left;
                while (tmp->right != NULL)
                    tmp = tmp->right;
                tmp->right = node ->right;
                tmp = node;
                node = node->left;
            }
            delete tmp;
        }
    }
    
    void findAndDeleteMerging(int data) // searches for the data and calls the the deletion function
    {
        // two perameters that are needed in order for this function to ... function *ba dum tskk*
        Node *node = root;
        Node *prev = node;
        
        while (node != NULL)
        {
            if (node->info == data) break; //if the data matches the data in the function
            
            prev = node;
            
            if (data < node->info)
                node = node->left;
            else
                node = node->right;
        }
        
        if (node != 0 && node->info == data)
        {
            if (node == root)
            {
                deleteMerging(root);
                
                if(root->left != NULL)
                    root= root->left;
                
                else if(root->right != NULL)
                    root = root->right;
                
                else
                    cout << "BSTree Error: findAndDeleteMerging cannot operate because BSTree is empty." << endl;
            }
            
            else if (prev->left == node)
            {
                deleteMerging(prev->left);
                prev->left = NULL; // Does not return 0
            }
            
            else
            {
                deleteMerging(prev->right);
                prev->right = NULL; //does not return 0
            }
        }
        else if (root != 0)
            cout << "BSTree: The value '" << data << "' is not in the tree." << endl;
        
        else
            cout << "BSTree: The BSTree is empty." << endl;
    }
    
    void destroyTree(Node *&tmp)
    {
        if (tmp != NULL)
        {
            destroyTree(tmp->left);
            destroyTree(tmp->right);
            delete tmp;
        }
        tmp = NULL;
    }
    
    // ***** PRINTS ***** //
    void printRoot()
    {
        cout << "BSTree: Root print: " << root->info << endl
        << "----------------" << endl;
    }
    
    void printLevelOrder()
    {
        cout << "BSTree: LevelOrder print:" << endl;
        printLevelOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    void printPreOrder()
    {
        cout << "BSTree: PreOrder print:" << endl;
        printPreOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    void printInOrder()
    {
        cout << "BSTree: InOrder print:" << endl;
        printInOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    void printPostOrder()
    {
        cout << "BSTree: PostOrder print:" << endl;
        printPostOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    // ***** SEARCH & SIZE ***** //
    void search(int data)
    {
        cout << "BSTree: Searching for '" << data << "'... " << endl;
        
        int level = search(data, 1, root);
        
        if (level == 1) cout << "'" << data << "' is the root, Level 1." << endl;
        else if (level > 1) cout << "'" << data << "' was found at Level " << level << "." << endl;
        else cout << "'" << data << "' was not found." << endl;
        cout << "----------------" << endl;
    }
    
    void numberOfLevels()
    {
        cout << "BSTree: Number of Levels: " << height(root) << "." << endl;
        cout << "----------------" << endl;
    }
    
    void numberOfNodes()
    {
        cout << "BSTree: Number of Nodes: " << numberOfNodes(root) << "." << endl;
        cout << "----------------" << endl;
    }
    
    void isBalanced()
    {
        if (isBalanced(root)) cout << "BSTree is balanced." << endl;
        else cout << "BSTree is not balanced." << endl;
        cout << "----------------" << endl;
    }
    
private:
    Node *root;
    
    // ***** RECURSIVE FUNCTIONS ***** //
    void insert(int data, Node *tmp) // Recursive insert function //
    {
        if (root == NULL)
            root = new Node(data);
        
        else
        {
            if (data < tmp->info)
            {
                if(tmp->left != NULL)
                    insert(data, tmp->left);
                else
                    tmp->left = new Node (data);
            }
            
            else if (data >= tmp->info)
            {
                if(tmp->right != NULL)
                    insert(data, tmp->right);
                else
                    tmp->right = new Node (data);
            }
        }
    }
    
    void printLevelOrder(Node *tmp)
    {
        int h = height(tmp);
        for (int i = 1; i <= h; i++)
            printGivenLevel(tmp, i);
    }
    
    void printGivenLevel(Node *tmp, int level)
    {
        if (root == NULL)
            cout << "BSTree Error: printLevelOrder failed because BSTree does not exist." << endl;
        
        else
        {
            if (tmp == NULL)
                return;
            
            if (level == 1)
                cout << tmp->info << " ";
            
            else if (level > 1)
            {
                printGivenLevel(tmp->left, level-1);
                printGivenLevel(tmp->right, level-1);
            }
        }
    }
    
    void printPreOrder(Node *tmp)
    {
        if (root == NULL)
            cout << "BSTree Error: printLevelOrder failed because BSTree does not exist." << endl;
        
        else if (tmp != NULL)
        {
            cout << tmp->info << " ";
            printPreOrder(tmp->left);
            printPreOrder(tmp->right);
        }
    }
    
    void printInOrder(Node *tmp)
    {
        if (root == NULL)
            cout << "BSTree Error: printInOrder failed because BSTree does not exist." << endl;
        
        else if (tmp != NULL)
        {
            printInOrder(tmp->left);
            cout << tmp->info << " ";
            printInOrder(tmp->right);
        }
    }
    
    void printPostOrder(Node *tmp)
    {
        if (root == NULL)
            cout << "BSTree Error: printPostOrder failed because BSTree does not exist." << endl;
        
        else if (tmp != NULL)
        {
            printPostOrder(tmp->left);
            printPostOrder(tmp->right);
            cout << tmp->info << " ";
        }
    }
    
    int height(Node *tmp)
    {
        if (tmp == NULL)
            return 0;
        
        else
        {
            int left = height(tmp->left); // Recursive calls for depth-first //
            int right = height(tmp->right);
            
            if (left > right) return (left+1);  // if the left is larger, return left
            else return (right+1);              // +1 to compensate for the recursion missing one
        }
    }
    
    int search(int data, int level, Node *tmp)
    {
        if (tmp == NULL) return 0;
        if (tmp->info == data) return level;
        
        int reclevel = search(data, level+1, tmp->left);
        if (reclevel != 0) return reclevel;
        
        reclevel = search(data, level+1, tmp->right);
        return reclevel;
    }
    
    int numberOfNodes(Node *tmp)
    {
        int count = 1;
        
        if (tmp->left != NULL)
            count += numberOfNodes(tmp->left);
        
        if (tmp->right != NULL)
            count += numberOfNodes(tmp->right);
        
        return count;
    }
    
    bool isBalanced(Node *tmp)
    {
        if(tmp == NULL)
            return 0; // Can't be balanced if it doesn't exist
        
        int left;
        int right;
        
        left = height(tmp->left);
        right = height(tmp->right);
        
        if(left-right <= 1 && isBalanced(tmp->left) && isBalanced(tmp->right))
            return 1;
        
        if(left-right > 1 && isBalanced(tmp->left) && isBalanced(tmp->right))
            return 0;
        
        return 0; // Default return
    }
};
