#include "PllNode.h"

PllNode* AllocPllNode(void) {
	return (PllNode*)malloc(sizeof(PllNode));
}

void SetPllNode(PllNode* n, const Data x, PllNode* next) {
	n->data = x;
	n->next = next;
}