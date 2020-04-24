#include "QuickSort.h"

void QuickSort(int* arr, int s, int e) { 
	
	int pl = s;
	int pr = e;
	int x = arr[(pl + pr) / 2];		// mid value 
	
	while(pl <= pr) {				// divide values of array into two groups, smaller group and bigger group.
		while(arr[pl] < x) pl++;
		while(arr[pr] > x) pr--;
		if(pl <= pr) {
			swap(arr[pl], arr[pr]);
			pl++;
			pr--;
		}
	}
	if(s < pr) QuickSort(arr, s, pr);	// re-apply quick sort to divided two groups of array. 
	if(pl < e) QuickSort(arr, pl, e);
}

void QuickSort2(int* arr, int n) {
	
	int pl = 0;
	int pr = n;
	int x = arr[ pr / 2 ];
	
	while(pl <= pr) {
		while(arr[pl] < x) pl++;
		while(arr[pr] > x) pr--;
		if(pl <= pr) {
			swap(arr[pl], arr[pr]);
			pl++;
			pr--;
		}
	}
	if(pr > 0) QuickSort2(arr, pr);
	if(pl < n) QuickSort2(arr+pl, n-pl);
}