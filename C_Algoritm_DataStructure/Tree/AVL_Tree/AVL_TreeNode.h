/*
	Binary Search Tree. Using feature of binary search, It has relatively faster insertion, delete, and finding of a data.
*/

#ifndef AVL_TREENODE_H
#define AVL_TREENODE_H

#include "../../Base/Base.h"

// Node datatype of AVL Tree. Basic unit of AVL Tree.
typedef struct __anode {
	struct __anode* left;	// Pointer variable that points out left childnode.
	struct __anode* right;	// Pointer variable that points out right childnode.
	Data data;	// Data that node contains.
} AVLNode;

AVLNode* AllocAVLNode(Data data, AVLNode* left, AVLNode* right);

// Get Height of tree node.
static int GetHeight(AVLNode* node);

// Get balancing factor of tree node, which is factor about rebalancing of nodes.
static int GetBFactor(AVLNode* node);

// Make tree with balanced form by rotating LL
static AVLNode* RotateLL(AVLNode* node);

// Make tree with balanced form by rotating RR
static AVLNode* RotateRR(AVLNode* node);

// Make tree with balanced form by rotating LR
static AVLNode* RotateLR(AVLNode* node);

// Make tree with balanced form by rotating RL
static AVLNode* RotateRL(AVLNode* node);

// Make tree with balanced form
AVLNode* Rebalance(AVLNode** node);

#endif