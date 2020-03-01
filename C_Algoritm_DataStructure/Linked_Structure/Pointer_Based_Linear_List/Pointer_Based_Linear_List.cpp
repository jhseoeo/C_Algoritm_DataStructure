#include "Pointer_Based_Linear_List.h"

static Node* AllocNode(void) {
	return (Node*)malloc(sizeof(Node));
}

static void SetNode(Node* n, const int x, Node* next) {
	n->data = x;
	n->next = next;
}

static Ptr_LinearList MakePtrLinearList() {
	Ptr_LinearList list;
	list.cur = list.head = NULL;
}

static Node* Search(const Ptr_LinearList &list, int x) {
	Node* ptr = list.head;
	while (ptr != NULL) {
		if (ptr->data == x)
			return ptr;
		ptr = ptr->next;
	}
	return NULL;
}

static void InsertFront(Ptr_LinearList* list, int x) {
	Node* newNode = AllocNode();
	SetNode(newNode, x, list->head);
	list->head = newNode;
}

static void InsertRear(Ptr_LinearList* list, int x) {
	if (list->head == NULL) {
		InsertFront(list, x);
	}
	else {
		Node* ptr = list->head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = AllocNode();
		SetNode(ptr->next, x, NULL);
	}
}

static void RemoveFront(Ptr_LinearList* list) {

}

static void RemoveRear(Ptr_LinearList* list) {

}

void Pointer_Based_Linear_List_Main() {

}	