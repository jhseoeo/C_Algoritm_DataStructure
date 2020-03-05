/*
	Node datatype . Basic unit of pointer based linear linked list.
*/
#ifndef NODE_H
#define NODE_H

#include "../../Base/Base.h"

// Node datatype. Basic unit of pointer based linear linked list.
typedef struct __node {
	int data;
	struct __node* next;
} pllNode;

// Allocate new empty node
pllNode* AllocNode(void);

// Set node's data.
void SetNode(pllNode* n, const int x, pllNode* next);

#endif