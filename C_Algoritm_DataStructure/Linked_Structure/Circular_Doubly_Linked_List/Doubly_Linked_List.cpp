#include "Doubly_Linked_List.h"

static CdllNode* Search(const CircularLinkedList& list, int x) {
	if (list.head != NULL) {
		CdllNode* c = list.head;
		do {
			if (c->data = x)
				return c;
			c = c->next;
		} while (c != list.head);
	}
	return NULL;
}

static void InsertFront(CircularLinkedList* list, int x) {
	CdllNode* node = AllocCdllNode();
	CdllNode* iPoint = list->head;

	if (iPoint != NULL) {
		iPoint->prev->next = node;
		SetCdllNode(node, x, iPoint, iPoint->prev);
		iPoint->prev = node;
	} else {
		SetCdllNode(node, x, node, node);
	}
	list->head = node;
}

static void InsertRear(CircularLinkedList* list, int x) {
	CdllNode* node = AllocCdllNode();

	if (list->head != NULL) {
		CdllNode* iPoint = list->head->prev;
		iPoint->next->prev = node;
		SetCdllNode(node, x, iPoint->next, iPoint);
		iPoint->next = node;
	} else {
		InsertFront(list, x);
		return;
	}
}

static void RemoveFront(CircularLinkedList* list) {
	CdllNode* rPoint = list->head;

	if (rPoint == NULL) {
		return;
	} else if (rPoint->next == rPoint) {
		list->head = NULL;
	} else {
		list->head = rPoint->next;
		rPoint->next->prev = rPoint->prev;
		rPoint->prev->next = rPoint->next;
	}
	free(rPoint);
}

static void RemoveRear(CircularLinkedList* list) {
	if (list->head == NULL) {
		return;
	} else if (list->head->next == list->head) {
		RemoveFront(list);
		return;
	} else {
		CdllNode* rPoint = list->head->prev;
		rPoint->next->prev = rPoint->prev;
		rPoint->prev->next = rPoint->next;
		free(rPoint);
	}
}

static void RemoveCursor(CircularLinkedList* list) {
	if (list->head == NULL || list->cur == NULL) {
		return;
	} else if (list->head->next == list->head) {
		RemoveFront(list);
		return;
	} else {
		CdllNode* rPoint = list->cur;
		rPoint->next->prev = rPoint->prev;
		rPoint->prev->next = rPoint->next;
		free(rPoint);
		list->cur = NULL;
	}
}

static void Clear(CircularLinkedList* list) {
	while (list->head != NULL) {
		RemoveFront(list);
	}
}

static CircularLinkedList MakeCircularDoublyLinkedList() {
	CircularLinkedList list;
	list.cur = list.head = NULL;
	return list;
}

void Circular_Doubly_Linked_List_Main() {
	
}