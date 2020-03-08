/*
	Node datatype. Basic unit of pointer based linear linked list.
*/

#ifndef DCLLNODE_H
#define DCLLNODE_H

#include "../../Base/Base.h"

// Node datatype. Basic unit of pointer based linear linked list.
typedef struct __node {
	__node* next;
	__node* prev;
	int data;
} CdllNode;

// Allocate new empty node
CdllNode* AllocCdllNode(void);

// Set node's data.
void SetCdllNode(CdllNode* n, const int x, CdllNode* next, CdllNode* prev);

#endif