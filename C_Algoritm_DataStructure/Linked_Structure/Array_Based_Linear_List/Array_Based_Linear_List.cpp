#include "Array_Based_Linear_List.h"

static Index Search(Arr_LinearList* list, int x) {
	for (Index i = 0; i < SIZE; i++) {
		if (list->n[i].data == x)
			return i;
	}
	return EMPTY;
}

static void InsertFront(Arr_LinearList* list, int x) {
	if (list->deleted == EMPTY)
		return;
	
	Index idx = list->deleted;
	list->deleted = list->n[idx].next;
	list->n[idx].next = list->Head;
	list->Head = idx;
	list->n[idx].data = x;
}

static void InsertRear(Arr_LinearList* list, int x) {
	if (list->deleted == EMPTY)
		return;

	Index i;
	for (i = list->Head; list->n[i].next != EMPTY; i = list->n[i].next);
	list->n[i].next = list->deleted;
	list->deleted = list->n[list->deleted].next;
	list->n[list->n[i].next].next = EMPTY;
	list->n[list->n[i].next].data = x;
}

static void RemoveFront(Arr_LinearList* list) {
	if (list->Head == NULL)
		return;


}

static Arr_LinearList MakeArrLinearList() {
	Arr_LinearList list;
	list.n = (Node*)malloc(SIZE * sizeof(Node));
	list.Head = list.cur = EMPTY;
	list.deleted = 0;
	for (Index i = 0; i < SIZE - 1; i++) {
		list.n[i].data = i + 1;
	}
	list.n[SIZE - 1].data = EMPTY;
	return list;
}

