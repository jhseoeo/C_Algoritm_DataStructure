#include "Doubly_Linked_List.h"

static CdllNode* Search(const CircularLinkedList& list, Data x) {
	if (list.head != NULL) {
		CdllNode* c = list.head;
		do {
			if (c->data == x)
				return c;
			c = c->next;
		} while (c != list.head);
	}
	return NULL;
}

static void InsertFront(CircularLinkedList* list, Data x) {
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

static void InsertRear(CircularLinkedList* list, Data x) {
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

static void MoveCur(CircularLinkedList* list, Data x) {
	list->cur = Search(*list, x);
}

static void PrintCur(const CircularLinkedList& list) {
	if (list.cur != NULL) {
		printf("%d", list.cur->data);
	} else {
		printf("NULL");
	}
}

static void PrintAll(const CircularLinkedList& list) {
	if (list.head != NULL) {
		CdllNode* ptr = list.head;
		printf("%d ", ptr->data);
		for (ptr = ptr->next; ptr != list.head; ptr = ptr->next)
			printf("%d ", ptr->data);
	}
}

static void Terminate(CircularLinkedList* list) {
	Clear(list);
}

static CircularLinkedList MakeCircularDoublyLinkedList() {
	CircularLinkedList list;
	list.cur = list.head = NULL;
	return list;
}


void Circular_Doubly_Linked_List_Main() {

	CircularLinkedList list = CircularLinkedList();
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
		printf(">> "); scanf("%d", &input); putchar('\n');

		switch (input) {
		case 1:
			printf("Enter the value that you want to insert into list\n");
			printf(">> "); scanf("%d", &input); printf("\n");
			InsertFront(&list, input);
			break;
		case 2:
			printf("Enter the value that you want to insert into list\n");
			printf(">> "); scanf("%d", &input); printf("\n");
			InsertRear(&list, input);
			break;
		case 3:
			RemoveFront(&list);
			break;
		case 4:
			RemoveRear(&list);
			break;
		case 5:
			RemoveCursor(&list);
			break;
		case 6:
			Clear(&list);
			break;
		case 7:
			printf("Enter the value that you want to search\n");
			printf(">> "); scanf("%d", &input); printf("\n");
			MoveCur(&list, input);
			break;
		case 0:
			Terminate(&list);
			goto ENDLOOP;
			break;
		default:
			break;
		}
	} ENDLOOP:;
}