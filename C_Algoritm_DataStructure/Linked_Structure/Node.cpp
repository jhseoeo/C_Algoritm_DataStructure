#include "Node.h"

Node* AllocNode(void) {
	return (Node*)malloc(sizeof(Node));
}

void SetNode(Node* n, const int x, Node* next) {
	n->data = x;
	n->next = next;
}