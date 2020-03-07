/*

*/

#ifndef DCLLNODE_H
#define DCLLNODE_H

typedef struct __node {
	__node* next;
	__node* prev;
	int data;
} DcllNode;

void AllocDcllNode;

#endif