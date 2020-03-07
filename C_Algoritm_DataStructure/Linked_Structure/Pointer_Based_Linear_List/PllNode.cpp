#include "PllNode.h"

pllNode* AllocNode(void) {
	return (pllNode*)malloc(sizeof(pllNode));
}

void SetNode(pllNode* n, const int x, pllNode* next) {
	n->data = x;
	n->next = next;
}