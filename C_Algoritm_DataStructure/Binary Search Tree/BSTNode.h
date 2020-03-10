/*
	Each
*/

#ifndef BSTNODE_H
#define BSTNODE_H

#include "../Base/Base.h"

typedef struct __bnode {
	struct __bnode* left;
	struct __bnode* right;
	Data data;
} BSTNode;

BSTNode* AllocBSTNode();

void SetBSTNode(BSTNode* node);

static BSTNode* Search(BSTNode* p, const Data n);

static void Add(BSTNode* p, const Data n);

static void Remove(BSTNode* p, const Data n);

static void Print(BSTNode* p);

static void Terminate(BSTNode* p);

#endif