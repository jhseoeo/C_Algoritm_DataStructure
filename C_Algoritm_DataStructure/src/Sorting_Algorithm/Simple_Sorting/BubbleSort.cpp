#include "BubbleSort.h"

#include "stdio.h"

void BubbleSort(int* arr, int s, int f) {
	for(int i = f - 1; i > s; i--) {
		for(int j = s; j < i; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}

	// An improved version. If the values of non-sorted part are already sorted, stops sorting.
	// for(int i = f; i > s;) {
	// 	int last = s;
	// 	for(int j = s + 1; j < i; j++) {
	// 		if (arr[j] < arr[j-1]) {
	// 			swap(arr[j], arr[j-1]);
	// 			last = j;
	// 		}
	// 	}
	// 	i = last;
	// }
}

// It bubbles maximun/minimum up both sides.
void CocktailSort(int* arr, int f, int e) {
	int wtr = 0;
	for(int i = 0; i < e; i++) {
		if(wtr) {
			for(int j = (i/2) + 1; j < e - (i/2); j++) {
				if(arr[j-1] > arr[j])
					swap(arr[j-1], arr[j]);
			}
			wtr--;
		} else {
			for(int j = e - (i/2) - 1; j > (i/2); j--) {
				if(arr[j-1] > arr[j])
					swap(arr[j-1], arr[j]);
			}
			wtr++;
		}
	}
}