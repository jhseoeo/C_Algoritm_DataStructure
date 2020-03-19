/*
	Node datatype of linked queue. Basic unit of linked queue.
*/

#ifndef LINKEDQUEUENODE_H
#define LINKEDQUEUENODE_H

#include "../../Base/Base.h"

// Node datatype of linked queue. Basic unit of linked queue.
typedef struct __linkedqueuenode {
	struct __linkedqueuenode* next;
	Data data;
} LqueueNode;

// Allocate new empty linked queue node.
LqueueNode* AllocLqueueNode();

// Set linked queue node's data.
void SetLqueueNode(LqueueNode* node, LqueueNode* next, Data data);

#endif