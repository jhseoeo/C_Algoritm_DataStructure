#include "DequeNode.h"

DequeNode* AllocDequeNode() {
	DequeNode* node = (DequeNode*)malloc(sizeof(DequeNode));
	node->next = node->prev = NULL;
	return node;
}

void SetDequeNode(DequeNode* node, DequeNode* next, DequeNode* prev, Data data) {
	node->next = next;
	node->prev = prev;
	node->data = data;
}