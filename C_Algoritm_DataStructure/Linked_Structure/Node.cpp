#include "Node.h"

static Node* AllocNode(void) {
	return (Node*)malloc(sizeof(Node));
}

static void SetNode(Node* n, const int x, Node* next) {
	n->data = x;
	n->next = next;
}