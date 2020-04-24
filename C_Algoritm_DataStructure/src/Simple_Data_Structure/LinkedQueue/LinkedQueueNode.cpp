#include "LinkedQueueNode.h"

LqueueNode* AllocLqueueNode() {
	LqueueNode* node = (LqueueNode*)malloc(sizeof(LqueueNode));
	node->next = NULL;
	return node;
}

void SetLqueueNode(LqueueNode* node, LqueueNode* next, Data data) {
	node->next = next;
	node->data = data;
}