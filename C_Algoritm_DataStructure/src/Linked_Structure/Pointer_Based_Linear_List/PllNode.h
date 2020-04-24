/*
	Node datatype. Basic unit of pointer based linear linked list.
*/

#ifndef PLLNODE_H
#define PLLNODE_H

#include "../../Base/Base.h"

// Node datatype. Basic unit of pointer based linear linked list.
typedef struct __pnode {
	Data data;	// Data that node contains
	struct __pnode* next;	// Pointer variable that points out next node.
} PllNode;

// Allocate new empty node
PllNode* AllocPllNode(void);

// Set node's data.
void SetPllNode(PllNode* n, const Data x, PllNode* next);

#endif