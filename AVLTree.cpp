//
//  AVLTree.cpp
//  Trees
//
//  Created by Nitin K on 5/2/19.
//  Copyright © 2019 CSCI 373. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Node.h"
using namespace std;

class AVLTree
// A self-balancing BST where the difference between heights of left and right subtrees cannot be more than one for all nodes
// Uses rotation to move things into their proper place
{
public:
    AVLTree()
    { root = NULL; }
    
    ~AVLTree()
    {
        cout << "AVLTree Warning: Destructor called." << endl;
        destroyTree(*&root);
        cout << "----------------" << endl;
    }
    
    // ***** INSERTION ***** //
    void insert(int data)
    {
        root = insert(root, data);
    }
    
    void autoFill(int amount)   // Function to automatically fill the tree...
    {                           // ...with random numbers //
        for(int i = 0; i < amount; i++)
            insert(rand()%1000);
    }
    
    // ***** ROTATION ***** //
    ANode *LLrotation(ANode *parent)
    {
        ANode *tmp = parent->right;
        ANode *tmp2 = tmp->left;
        
        // Perform rotation
        tmp->left = parent;
        parent->right = tmp2;
        
        // Update heights
        parent->height = max(height(parent->left),
                        height(parent->right)) + 1;
        tmp->height = max(height(tmp->left),
                        height(tmp->right)) + 1;
        
        // Return new root
        return tmp;
    }
    
    ANode *RRrotation(ANode *parent)
    {
        ANode *tmp = parent->left;
        ANode *tmp2 = tmp->right;
        
        // Perform rotation
        tmp->right = parent;
        parent->left = tmp2;
        
        // Update heights
        parent->height = max(height(parent->left),
                             height(parent->right)) + 1;
        tmp->height = max(height(tmp->left),
                          height(tmp->right)) + 1;
        
        // Return new root
        return tmp;
    }
    
    ANode *LRrotation(ANode *parent)
    {
        parent->left = RRrotation(parent->left);
        parent = LLrotation(parent);
        return parent;
    }

    ANode *RLrotation(ANode *parent)
    {
        parent->right = LLrotation(parent->right);
        parent = RRrotation(parent);
        return parent;
    }
    
    // ***** BALANCE ***** //
    ANode *balance(ANode *tmp)
    {
        int BFactor = getBFactor(tmp);
        
        if (BFactor > 1)
        {
            if (getBFactor(tmp->left) > 0)
                tmp = LLrotation(tmp);
            else
                tmp = LRrotation(tmp);
        }
        
        else if (BFactor < -1)
        {
            if (getBFactor(tmp->right) > 0)
                tmp = RLrotation(tmp);
            else
                tmp = RRrotation(tmp);
        }
        return tmp;
    }
    
    // ***** DELETION ***** //
    void deleteHalf()
    {
        int halfsize = numberOfNodes(root) / 2;
        
        while (numberOfNodes(root) > halfsize)
            findAndDeleteMerging(rand()%1000);
    }
    
    void deleteMerging(ANode *node) // Using a merging alogrithim
    {
        ANode *tmp = node;        //passes the value to a pointer Node *node
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
        ANode *node = root;
        ANode *prev = node;
        
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
                    cout << "AVLTree Error: findAndDeleteMerging cannot operate because AVLTree is empty." << endl;
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
            cout << "AVLTree: The value '" << data << "' is not in the tree." << endl;
        
        else
            cout << "AVLTree: The BinaryTree is empty." << endl;
    }
    
    void destroyTree(ANode *&tmp)
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
        cout << "AVLTree: Root print: " << root->info << endl
        << "----------------" << endl;
    }
    
    void printPreOrder()
    {
        cout << "AVLTree: PreOrder print:" << endl;
        printPreOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    void printInOrder()
    {
        cout << "AVLTree: InOrder print:" << endl;
        printInOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    void printPostOrder()
    {
        cout << "AVLTree: PostOrder print:" << endl;
        printPostOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    // ***** SEARCH & SIZE ***** //
    void search(int data)
    {
        cout << "AVLTree: Searching for '" << data << "'... " << endl;
        
        int level = search(data, 1, root);
        
        if (level == 1) cout << "'" << data << "' is the root, Level 1." << endl;
        else if (level > 1) cout << "'" << data << "' was found at Level " << level << "." << endl;
        else cout << "'" << data << "' was not found." << endl;
        cout << "----------------" << endl;
    }
    
    void numberOfLevels()
    {
        cout << "AVLTree: Number of Levels: " << height(root) << "." << endl;
        cout << "----------------" << endl;
    }
    
    void numberOfNodes()
    {
        cout << "AVLTree: Number of Nodes: " << numberOfNodes(root) << "." << endl;
        cout << "----------------" << endl;
    }
    
    void isBalanced()
    {
        if (isBalanced(root)) cout << "AVLTree is balanced." << endl;
        else cout << "AVLTree is not balanced." << endl;
        cout << "----------------" << endl;
    }
    
    void printBalanceFactor()
    {
        cout << "AVLTree: Balance Factor: " << getBFactor(root) << " ." << endl;
        cout << "----------------" << endl;
    }
    
private:
    ANode *root;
    
    // ***** RECURSIVE FUNCTIONS ***** //
    ANode *insert(ANode *tmp, int data)
    {
        // Normal insertion from BST //
        if (tmp == NULL)
            return (new ANode(data));
        
        if (data < tmp->info)
            tmp->left = insert(tmp->left, data);
        else if (data > tmp->info)
            tmp->right = insert(tmp->right, data);
        
        // Updating Height //
        tmp->height = 1 + max(height(tmp->left), height(tmp->right));
        
        // Check balance //
        int bal = getBFactor(tmp);
        
        if (bal > 1 && data < tmp->left->info) // if Left-Left
            return RRrotation(tmp);
        
        if (bal < -1 && data > tmp->right->info) // if Right-Right
            return LLrotation(tmp);
        
        if (bal > 1 && data > tmp->left->info) // if Left-Right
        {
            tmp->left = LLrotation(tmp->left);
            return RRrotation(tmp);
        }
        
        if (bal < -1 && data < tmp->right->info) // if Right-Left
        {
            tmp->right = RRrotation(tmp->right);
            return LLrotation(tmp);
        }
        
        return tmp;
    }
    
    void printPreOrder(ANode *tmp)
    {
        if (root == NULL)
            cout << "AVLTree Error: printLevelOrder failed because AVLTree does not exist." << endl;
        
        else if (tmp != NULL)
        {
            cout << tmp->info << " ";
            printPreOrder(tmp->left);
            printPreOrder(tmp->right);
        }
    }
    
    void printInOrder(ANode *tmp)
    {
        if (root == NULL)
            cout << "AVLTree Error: printInOrder failed because AVLTree does not exist." << endl;
        
        else if (tmp != NULL)
        {
            printInOrder(tmp->left);
            cout << tmp->info << " ";
            printInOrder(tmp->right);
        }
    }
    
    void printPostOrder(ANode *tmp)
    {
        if (root == NULL)
            cout << "AVLTree Error: printPostOrder failed because AVLTree does not exist." << endl;
        
        else if (tmp != NULL)
        {
            printPostOrder(tmp->left);
            printPostOrder(tmp->right);
            cout << tmp->info << " ";
        }
    }
    
    int height(ANode *tmp)
    {
        if (tmp == NULL)
            return 0;
        return tmp->height;
    }
    
    int search(int data, int level, ANode *tmp)
    {
        if (tmp == NULL) return 0;
        if (tmp->info == data) return level;
        
        int reclevel = search(data, level+1, tmp->left);
        if (reclevel != 0) return reclevel;
        
        reclevel = search(data, level+1, tmp->right);
        return reclevel;
    }
    
    int numberOfNodes(ANode *tmp)
    {
        int count = 1;
        
        if (tmp->left != NULL)
            count += numberOfNodes(tmp->left);
        
        if (tmp->right != NULL)
            count += numberOfNodes(tmp->right);
        
        return count;
    }
    
    bool isBalanced(ANode *tmp)
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
    
    int getBFactor(ANode *tmp) // get Balance Factor of the AVL Tree
    {
        if (tmp == NULL)
            return 0;
        return height(tmp->left) - height(tmp->right);
    }
    
    int max(int a, int b)
    {
        return (a > b)? a : b;
    }
};
