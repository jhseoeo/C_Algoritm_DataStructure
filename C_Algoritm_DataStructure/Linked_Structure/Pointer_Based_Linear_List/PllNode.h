/*
	Node datatype . Basic unit of pointer based linear linked list.
*/
#ifndef PLLNODE_H
#define PLLNODE_H

#include "../../Base/Base.h"

// Node datatype. Basic unit of pointer based linear linked list.
typedef struct __node {
	int data;
	struct __node* next;
} PllNode;

// Allocate new empty node
PllNode* AllocPllNode(void);

// Set node's data.
void SetPllNode(PllNode* n, const int x, PllNode* next);

#endif