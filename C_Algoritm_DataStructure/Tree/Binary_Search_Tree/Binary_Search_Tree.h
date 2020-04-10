/*
	Binary Search Tree. Using feature of binary search, It has relatively faster insertion, delete, and finding of a data.
*/

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "../../Base/Base.h"

// Node datatype of Binary search tree. Basic unit of Binary search tree.
typedef struct __bnode {
	struct __bnode* left;	// Pointer variable that points out left childnode.
	struct __bnode* right;	// Pointer variable that points out right childnode.
	Data data;	// Data that node contains
} BSTNode;

// Retype bst
typedef BSTNode* BinarySearchTree;


// Allocate new empty binary search tree node.
BSTNode* AllocBSTNode();

// Set binary search tree node's data.
void SetBSTNode(BSTNode* node, BSTNode* leftChild, BSTNode* rightChild, Data data);

// Search Data from BSTNode and its descendant nodes.
static BSTNode* Search(BSTNode* p, const Data n);

// Add new data.
static void Add(BSTNode* &p, const Data n);

// Remove data while keep it as binary search tree.
static void Remove(BSTNode** root, BSTNode* p);

// Print BSTNode and its all descendant nodes as inorder.
static void Print(BSTNode* p);

// Terminate BSTNode and its all descendant nodes.
static void Clear(BSTNode* p);


// Main function of Binary Search Tree
void Binary_Search_Tree_Main();

#endif