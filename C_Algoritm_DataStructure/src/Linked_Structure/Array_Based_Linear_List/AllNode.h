/*
	Node datatype. Basic unit of array based linear linked list.
*/
#ifndef ALLNODE_H
#define ALLNODE_H

#include "../../Base/Base.h"

// symbol of empty cursor.
#define EMPTY -1

// type of cursor
typedef int Index;

// Node datatype. Basic unit of array based linear linked list.
typedef struct {
	Data data;	// Data that node contains
	Index next;	// Index variable that points out next node.
} AllNode;

#endif