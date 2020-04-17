/*
	Binary Search Tree. Using feature of binary search, It has relatively faster insertion, delete, and finding of a data.
*/

#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "../../Base/Base.h"
#include "AVL_TreeNode.h"

// Retype avl tree
typedef AVLNode* AVLTree;

// Search Data from BSTNode and its descendant nodes.
static AVLNode* Search(AVLNode* p, const Data n);

// Add new data.
static void Add(AVLNode** p, const Data n);

// Remove data while keep it as binary search tree.
static void Remove(AVLNode** root, AVLNode* p);

// Print BSTNode and its all descendant nodes as inorder.
static void Print(AVLNode* p);

// Terminate BSTNode and its all descendant nodes.
static void Clear(AVLNode* p);

// Main function of Binary Search Tree
void AVL_Tree_Main();

#endif