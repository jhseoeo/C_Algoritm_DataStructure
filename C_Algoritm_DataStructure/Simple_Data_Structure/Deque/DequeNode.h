/*
	Node datatype of deque. Basic unit of deque.
*/

#ifndef DEQUENODE_H
#define DEQUENODE_H

#include "../../Base/Base.h"

// Node datatype of deque. Basic unit of deque.
typedef struct __dequenode {
	struct __dequenode* next;
	Data data;
} DequeNode;

// Allocate new empty deque node.
DequeNode* AllocDequeNode();

// Set deque node's data.
void SetDequeNode(DequeNode* node, DequeNode* next, Data data);

#endif