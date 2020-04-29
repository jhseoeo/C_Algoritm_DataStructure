#include "HeapSort.h"

void HeapSort(int* arr, int s, int e) {
	for(int i = (s + e) / 2; i >= s; i--)			// Make the array heap.
		ReHeapDown(arr, i, e);
	for(int i = e; i > s; i--) {					// Sorting array.
		if(arr[s] > arr[i])
			swap(arr[s], arr[i]);
		ReHeapDown(arr, s, i-1);
	}
}

void ReHeapDown(int* arr, int s, int e) { 
	int i = s;
	while(true) {
		if (i*2 + 2 > e) break;
		int bigger = (arr[i*2 + 1] >= arr[i*2 + 2] ? i*2 + 1 : i*2 + 2);
		if (arr[i] < arr[bigger]) {
			swap(arr[i], arr[bigger]);
			i = bigger;
		}
		else
			break;	
	}
}