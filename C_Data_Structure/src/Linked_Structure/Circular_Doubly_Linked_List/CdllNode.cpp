#include "CdllNode.h"

CdllNode* AllocCdllNode(void) {
	return (CdllNode*)malloc(sizeof(CdllNode));
}

void SetCdllNode(CdllNode* n, const Data x, CdllNode* next, CdllNode* prev) {
	n->data = x;
	n->next = next;
	n->prev = prev;
}