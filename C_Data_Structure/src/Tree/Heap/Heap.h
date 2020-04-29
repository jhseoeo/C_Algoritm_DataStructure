/*
	Heap datatype. It has tree structure, and implemented as max heap. So child nodes are bigger than each nodes.
*/

#ifndef HEAP_H
#define HEAP_H

#include "../../Base/Base.h" 

// Heap datatype. It has tree structure, and implemented as max heap. So child nodes are smaller than each parent nodes.
typedef struct {
	size_t size;	// Maximum number of data. 
	Data* arr;		// Data array. NOT USE ZERO INDEX
	int max;
} Heap;

// Insert a data into the heap.
int Heap_Insert(Heap* heap, Data data);

// Delete a data from the heap.
Data Heap_Delete(Heap* heap);

// Assuming that only the data of given index in heap isn't proper, make heap proper by moving data of given index down.
static void ReHeapDown(Heap* heap, int idx, int maxIdx);

// Assuming that datas of bigger indices than given index in heap are proper, make heap proper by moving data of given index up.
static void ReHeapUp(Heap* heap, int idx);

// Make an initialized heap.
Heap MakeNewHeap(int size);

#endif