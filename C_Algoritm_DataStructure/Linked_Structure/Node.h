/*
	Node datatype. Basic unit of linked structure
*/
#ifndef NODE_H
#define NODE_H

#include "../Base/Base.h"

// Node datatype. Basic unit of linked structure
typedef struct __node {
	int data;
	struct __node* next;
} Node;

// Allocate new empty node
Node* AllocNode(void);

// Set node's data.
void SetNode(Node* n, const int x, Node* next);

#endif