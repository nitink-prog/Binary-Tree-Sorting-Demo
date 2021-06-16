//
//  main.cpp
//  Trees
//
//  Created by Nitin K on 3/1/19.
//  Copyright © 2019 CSCI 373. All rights reserved.
//

#include <iostream>
#include "BinaryTree.cpp"
#include "BSTree.cpp"
#include "AVLTree.cpp"
#include "Heap.cpp"
using namespace std;

// ***** PROTOTYPES ***** //
//void openPanel(); // Broken as Hell
void demoBinaryTree();
void demoBSTree();
void demoAVLTree();
void demoMaxHeap();

// ***** MAIN ***** //
int main()
{
//    openPanel(); // Broken as Hell
//    demoBinaryTree();
    demoBSTree();
//    demoAVLTree();
//    demoMaxHeap();
    
    return 0;
}

// ***** FUNCTION DEFINITIONS ***** //
void demoBinaryTree()
{
    BinaryTree BT;
    
    BT.autoFill(100);
    BT.printRoot();
    BT.isBalanced();
    
    BT.numberOfLevels();
    BT.numberOfNodes();
    
    BT.printLevelOrder();
    BT.printPreOrder();
    BT.printInOrder();
    BT.printPostOrder();
    
    BT.deleteHalf();
    BT.numberOfLevels();
    BT.numberOfNodes();
    
    BT.printLevelOrder();
    BT.printPreOrder();
    BT.printInOrder();
    BT.printPostOrder();
    
    BT.search(rand()%1000);
    
    BT.~BinaryTree();
}

void demoBSTree()
{
    BSTree BST;
    
    BST.autoFill(100);
    BST.printRoot();
    BST.isBalanced();
    
    BST.numberOfLevels();
    BST.numberOfNodes();
    
    BST.printLevelOrder();
    BST.printPreOrder();
    BST.printInOrder();
    BST.printPostOrder();
    
    BST.deleteHalf();
    BST.numberOfLevels();
    BST.numberOfNodes();
    
    BST.printLevelOrder();
    BST.printPreOrder();
    BST.printInOrder();
    BST.printPostOrder();
    
    BST.search(rand()%1000);
    
    BST.~BSTree();
}

void demoAVLTree()
{
    AVLTree AVL;
    
    AVL.autoFill(100);
    AVL.printRoot();
    AVL.isBalanced();
    
    AVL.numberOfLevels();
    AVL.numberOfNodes();
    
    AVL.printPreOrder();
    AVL.printInOrder();
    AVL.printPostOrder();
    
    AVL.deleteHalf();
    AVL.numberOfLevels();
    AVL.numberOfNodes();
    
    AVL.printPreOrder();
    AVL.printInOrder();
    AVL.printPostOrder();
    
    AVL.search(rand()%1000);
    
    AVL.~AVLTree();
}

void demoMaxHeap()
{
    MaxHeap H;
    
    H.autoFill(100);
    H.printRoot();
    H.isBalanced();

    H.numberOfLevels();
    H.numberOfNodes();

    H.printPreOrder();
    H.printInOrder();
    H.printPostOrder();

    H.search(rand()%1000);
}

void demoMinHeap()
{
    MinHeap M;
    
    M.autoFill(100);
    M.printRoot();
    M.isBalanced();
    
    M.numberOfLevels();
    M.numberOfNodes();
    
    M.printPreOrder();
    M.printInOrder();
    M.printPostOrder();
    
    M.search(rand()%1000);
}

//void openPanel() // Broken as Hell
//{
//    cout << "Welcome to the Tree Panel." << endl
//    << "Select the Tree type you would like to test:" << endl
//    << "1. Binary Tree" << endl
//    << "2. Binary Search Tree" << endl
//    << "3. AVL Tree" << endl
//    << "4. Heap" << endl;
//
//    int input;
//    cin >> input;
//
//    while (input == 1 || input == 2 || input == 3 || input == 4)
//    {
//        switch (input)
//        {
//            case 1:
//            {
//                cout << "Binary Tree Functions:" << endl
//                << "1. Insert a Node" << endl
//                << "2. Delete a Node" << endl
//                << "3. Print Root" << endl
//                << "4. Print PreOrder" << endl
//                << "5. Print InOrder" << endl
//                << "6. Print PostOrder" << endl;
//                int input2;
//                cin >> input2;
//                switch (input2)
//                {
//                    case 1:
//                    {
//
//                        cout << "Binary Tree Insertion:" << endl
//                        << "Enter the value you would like to insert:" << endl;
//
//                        int data;
//                        cin >> data;
//
//                        BT.insert(data);
//
//
//                    }
//
//                    case 2:
//                    {
//                        cout << "Binary Tree Deletion:" << endl
//                        << "Enter the value you would like to delete:" << endl;
//
//                        int data;
//                        cin >> data;
//                        BT.findAndDeleteMerging(data);
//
//
//                    }
//
//                    default:
//                    {
//                        BinaryTree BT;
//                    }
//                }
//                break;
//            }
//
//            case 2:
//            {
//                BSTree BST;
//                cout << "Binary Search Tree Functions:" << endl
//                << "1. Insert a Node" << endl
//                << "2. Delete a Node" << endl
//                << "3. Print Root" << endl
//                << "4. Print PreOrder" << endl
//                << "5. Print InOrder" << endl
//                << "6. Print PostOrder" << endl;
//                break;
//            }
//
//            case 3:
//            {
//                cout << "AVL Tree Functions:" << endl
//                << "1. Insert a Node" << endl
//                << "2. Delete a Node" << endl
//                << "3. Print Root" << endl
//                << "4. Print PreOrder" << endl
//                << "5. Print InOrder" << endl
//                << "6. Print PostOrder" << endl;;
//                break;
//            }
//
//            case 4:
//            {
//                cout << "Heap Functions:" << endl
//                << "1. Insert a Node" << endl
//                << "2. Delete a Node" << endl
//                << "3. Print Root" << endl
//                << "4. Print PreOrder" << endl
//                << "5. Print InOrder" << endl
//                << "6. Print PostOrder" << endl;;
//                break;
//            }
//
//            default:
//            {
//                cout << "Invalid input." << endl;
//                break;
//            }
//        }
//    }
//}
