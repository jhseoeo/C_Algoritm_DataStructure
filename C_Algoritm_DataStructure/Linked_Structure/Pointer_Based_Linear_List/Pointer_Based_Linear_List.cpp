#include "Pointer_Based_Linear_List.h"



static Ptr_LinearList MakePtrLinearList() {
	Ptr_LinearList list;
	list.cur = list.head = NULL;
}

static Node* Search(const Ptr_LinearList &list, int x) {
	Node* ptr = list.head;
	while (ptr != NULL) {
		if (ptr->data == x) {
			return ptr;
		}
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
	} else {
		Node* ptr = list->head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = AllocNode();
		SetNode(ptr->next, x, NULL);
	}
}

static void RemoveFront(Ptr_LinearList* list) {
	if (list->head != NULL) {
		Node* ptr = list->head;
		list->head = list->head->next;
		free(ptr);
	}
}

static void RemoveRear(Ptr_LinearList* list) {
	if (list->head != NULL) {
		if (list->head->next == NULL) {
			RemoveFront(list);
		} else {
			Node* ptr = list->head;
			while (ptr->next->next != NULL) ptr = ptr->next;
			Node* del = ptr->next;
			ptr->next = NULL;
			free(del);
		}
	} 
}

static void RemoveCurrunt(Ptr_LinearList* list) {
	if (list->head = list->cur) {
		RemoveFront(list);
	} else {
		Node* ptr = list->head;
		while (ptr->next != list->cur) ptr = ptr->next;
		ptr->next = list->cur->next;
		free(list->cur);
		list->cur = list->head;
	}
}

static void Clear(Ptr_LinearList* list) {
	while (list->head != NULL) {
		RemoveFront(list);
	}
	list->cur = NULL;
}




static void Terminate(Ptr_LinearList* list) {
	Clear(list);
}

void Pointer_Based_Linear_List_Main() {

}	