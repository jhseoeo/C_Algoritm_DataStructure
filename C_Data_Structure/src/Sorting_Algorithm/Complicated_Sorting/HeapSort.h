/*
Heap Sort
Time Complexity : O(Nlog(N))
*/

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "../../Base/Base.h"

// Heap Sort Algoritm
void HeapSort(int* arr, int s, int e);

// Assuming that arr[s+1] ~ arr[e] is heap, by moving arr[s] correct location, make arr[s] ~ arr[e] heap.
void ReHeapDown(int* arr, int s, int e);

#endif