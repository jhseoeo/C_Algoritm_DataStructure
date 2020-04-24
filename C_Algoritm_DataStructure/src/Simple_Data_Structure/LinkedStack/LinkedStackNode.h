/*
	Node datatype of linked stack. Basic unit of linked stack.
*/

#ifndef LINKEDSTACKNODE_H
#define LINKEDSTACKNODE_H

#include "../../Base/Base.h"

// Node datatype of linked stack. Basic unit of linked stack.
typedef struct __linkedstacknode {
	struct __linkedstacknode* next;
	Data data;
} LstackNode;

// Allocate new empty linked stack node.
LstackNode* AllocLstackNode();

// Set linked stack node's data.
void SetLstackNode(LstackNode* node, LstackNode* next, Data data);

#endif