#include "Array_Based_Linear_List.h"

static Index Search(Arr_LinearList* list, Data x) {
	for (Index i = 0; i < SIZE; i++) {
		if (list->n[i].data == x)
			return i;
	}
	return EMPTY;
}

static void InsertFront(Arr_LinearList* list, Data x) {
	if (list->deleted == EMPTY)
		return;
	
	Index idx = list->deleted;
	list->deleted = list->n[idx].next;
	list->n[idx].next = list->Head;
	list->Head = idx;
	list->n[idx].data = x;
}

static void InsertRear(Arr_LinearList* list, Data x) {
	if (list->deleted == EMPTY)
		return;

	if (list->Head == EMPTY) {
		InsertFront(list, x);
		return;
	}

	Index i;
	for (i = list->Head; list->n[i].next != EMPTY; i = list->n[i].next);
	list->n[i].next = list->deleted;
	list->deleted = list->n[list->deleted].next;
	list->n[list->n[i].next].next = EMPTY;
	list->n[list->n[i].next].data = x;
}

static void RemoveFront(Arr_LinearList* list) {
	if (list->Head == EMPTY)
		return;

	Index i = list->Head;
	list->Head = list->n[i].next;
	list->n[i].next = list->deleted;
	list->deleted = i;
}

static void RemoveRear(Arr_LinearList* list) {
	if (list->Head == EMPTY)
		return;
	else if (list->n[list->Head].next == EMPTY)
		RemoveFront(list);

	Index i;
	for (i = list->Head; list->n[list->n[i].next].next != EMPTY; i = list->n[i].next);
	list->n[list->n[i].next].next = list->deleted;
	list->deleted = list->n[i].next;
	list->n[i].next = EMPTY;
}

static void RemoveCursor(Arr_LinearList* list) {
	if (list->Head == EMPTY || list->cur == EMPTY)
		return;
	else if(list->Head == list->cur)
		RemoveFront(list);

	Index i;
	for (i = list->Head; list->n[i].next != list->cur; i = list->n[i].next);
	list->n[i].next = list->n[list->cur].next;
	list->n[list->cur].next = list->deleted;
	list->deleted = list->cur;
	list->cur = EMPTY;
}

static void Clear(Arr_LinearList* list) {
	list->Head = list->cur = EMPTY;
	list->deleted = 0;
	for (Index i = 0; i < SIZE - 1; i++) {
		list->n[i].next = i + 1;
	}
	list->n[SIZE - 1].next = EMPTY;
}

static void MoveCur(Arr_LinearList* list, Data x) {
	list->cur = Search(list, x);
}

static void PrintCur(const Arr_LinearList& list) {
	if (list.cur != EMPTY)
		printf("%d", list.n[list.cur].data);
	else
		printf("NULL");
}

static void PrintAll(const Arr_LinearList& list) {
	if (list.Head == EMPTY)
		return;
	else {
		printf("%d ", list.n[list.Head].data);
		for (Index i = list.Head; list.n[i].next != EMPTY; i = list.n[i].next)
			printf("%d ", list.n[list.n[i].next].data);
	}
}

static void Terminate(Arr_LinearList* list) {
	free(list->n);
}

static Arr_LinearList MakeArrLinearList() {
	Arr_LinearList list;
	list.n = (AllNode*)malloc(SIZE * sizeof(AllNode));
	list.Head = list.cur = EMPTY;
	list.deleted = 0;
	for (Index i = 0; i < SIZE - 1; i++) {
		list.n[i].next = i + 1;
	}
	list.n[SIZE - 1].next = EMPTY;
	return list;
}

void Array_Based_Linear_List_Main() {

	Arr_LinearList list = MakeArrLinearList();
	printf("List created.\n");
	int input;
	while (1) {
		system(CLEAR);
		printf("list : "); PrintAll(list); printf("\n");
		printf("cursor is on "); PrintCur(list); printf("\n");
		printf("deleted : ");
		if (list.deleted != EMPTY) {
			printf("%d ", list.deleted);
			AllNode* node = &list.n[list.deleted];
			while (node->next != EMPTY) {
				printf("%d ", node->next);
				node = &list.n[node->next];
			}
		} else
			printf("Empty");
		printf("\n");
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
	} ENDLOOP: ;
}