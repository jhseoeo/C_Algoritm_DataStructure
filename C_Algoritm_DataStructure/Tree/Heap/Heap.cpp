#include "Heap.h"

static void swap(Data* a, Data* b) {
	Data temp = *a;
	*a = *b;
	*b = temp;
}

int Heap_Insert(Heap* heap, Data data) {
	if (heap->size >= heap->max)
		return 0;
	heap->arr[++heap->size];
	ReHeapUp(heap, heap->size);
	return 1;
}

Data Heap_Delete(Heap* heap) {
	Data temp = heap->arr[1];
	heap->arr[1] = heap->arr[heap->size--];
	ReHeapDown(heap, 1, heap->size);
	return temp;
}

static void ReHeapDown(Heap* heap, int idx, int maxIdx) {
	int i = 0;
	while (true) {
		if (heap->arr[i] >= heap->arr[i * 2] && heap->arr[i] >= heap->arr[i * 2 + 1]) {
			break;
		} else if (heap->arr[i] < heap->arr[i * 2]) {
			swap(heap->arr[i], heap->arr[i * 2]);
			i = i * 2;
		} else {
			swap(heap->arr[i], heap->arr[i * 2 + 1]);
			i = i * 2 + 1;
		}
	}
} 

static void ReHeapUp(Heap* heap, int idx) {
	int i = idx;
	while (i > 1) {
		if (heap->arr[i] > heap->arr[i / 2]) {
			swap(heap->arr[i], heap->arr[i / 2]);
		}
		i /= 2;
	}
}

Heap MakeNewHeap(int size) {
	Heap heap;
	heap.max = size;
	heap.size = 1;
	heap.arr = (Data*)malloc((size+1) * sizeof(Data));
	heap.arr[0] = 0;
	return heap;
}