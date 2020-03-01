#include "Pointer_Based_Linear_List.h"

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

static void MoveCur(Ptr_LinearList* list, int x) {
	list->cur = Search(*list, x);
}

static void PrintCur(const Ptr_LinearList& list) {
	printf("%d", list.cur->data);
}

static void PrintAll(const Ptr_LinearList& list) {
	for(Node* ptr = list.head; ptr != NULL; ptr = ptr->next)
		printf("%d ", ptr->data);
}

static void Terminate(Ptr_LinearList* list) {
	Clear(list);
}

static Ptr_LinearList MakePtrLinearList() {
	Ptr_LinearList list;
	list.cur = list.head = NULL;
}


void Pointer_Based_Linear_List_Main() {

	Ptr_LinearList list = MakePtrLinearList();
	printf("List created.\n");
	int input;
	while (1) {
		system(CLEAR);
		printf("list : "); PrintAll(list); printf("\n");
		printf("cursor is on "); PrintCur(list); printf("\n");
		printf("\n");
		printf("Menu\n");
		printf("1. Insert on front\n");
		printf("2. Insert on rear\n");
		printf("3. Remove on front\n");
		printf("4. Remove on rear\n");
		printf("5. Remove on cursor\n");
		printf("6. Clear\n");
		printf("7. Move Cursor\n");
		printf("0. End\n");
	}

}	