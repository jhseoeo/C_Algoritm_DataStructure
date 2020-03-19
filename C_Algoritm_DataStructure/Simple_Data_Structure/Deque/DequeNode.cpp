#include "DequeNode.h"

DequeNode* AllocDequeNode() {
	DequeNode* node = (DequeNode*)malloc(sizeof(DequeNode));
	node->next = NULL;
	return node;
}

void SetDequeNode(DequeNode* node, DequeNode* next, Data data) {
	node->next = next;
	node->data = data;
}