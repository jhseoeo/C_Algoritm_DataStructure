#include "LinkedStackNode.h"

LstackNode* AllocLstackNode() {
	LstackNode* node = (LstackNode*)malloc(sizeof(LstackNode));
	node->next = NULL;
	return node;
}

void SetLstackNode(LstackNode* node, LstackNode* next, Data data) {
	node->next = next;
	node->data = data;
}