#include "SelectionSort.h"

// It finds minimum value of non-sorted part, and puts it at precise location.
void SelectionSort(int* arr, int s, int e) {
	for(int i = s; i < e; i++) {
		int minIdx = i;
		for(int j = i; j < e; j++) {
			if(arr[j] < arr[minIdx])
				minIdx = j;
		}
		swap(arr[i], arr[minIdx]);
	}
}