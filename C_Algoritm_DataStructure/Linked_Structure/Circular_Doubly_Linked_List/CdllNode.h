/*
	Node datatype. Basic unit of pointer based linear linked list.
*/

#ifndef DCLLNODE_H
#define DCLLNODE_H

#include "../../Base/Base.h"

// Node datatype. Basic unit of pointer based linear linked list.
typedef struct __dnode {
	struct __dnode* next;	// Pointer variable that points out next node.
	struct __dnode* prev;	// Pointer variable that points out previous node.
	Data data;	// Data that node contains
} CdllNode;

// Allocate new empty node
CdllNode* AllocCdllNode(void);

// Set node's data.
void SetCdllNode(CdllNode* n, const Data x, CdllNode* next, CdllNode* prev);

#endif