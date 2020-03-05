/*
	Node datatype. Basic unit of array based linear linked list.
*/
#ifndef NODE_H
#define NODE_H

#include "../../Base/Base.h"

// symbol of empty cursor.
#define EMPTY -1

// type of cursor
typedef int Index;

// Node datatype. Basic unit of array based linear linked list.
typedef struct {
	int data;
	Index next;
} Node;

#endif