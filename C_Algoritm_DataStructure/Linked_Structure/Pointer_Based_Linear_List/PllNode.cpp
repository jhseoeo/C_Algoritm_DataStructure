#include "PllNode.h"

PllNode* AllocpllNode(void) {
	return (PllNode*)malloc(sizeof(PllNode));
}

void SetPllNode(PllNode* n, const int x, PllNode* next) {
	n->data = x;
	n->next = next;
}