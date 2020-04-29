#include <string.h>
#include "InsertionSort.h"
#include "../../Search_Algorithm/BinarySearch.h"

// It inserts values into appropriate location.
void InsertionSort(int* arr, int s, int e) {
	for(int j, i = s + 1; i < e; i++) {
		int temp = arr[i];
		for(j = i; j > s && arr[j - 1] > temp; j--) {
			arr[j] = arr[j-1];
		}
		arr[j] = temp;
	}
}

void BinaryInsertionSort(int* arr, int s, int e) {
	for(int i = s + 1; i < e; i++) {
		int temp = arr[i];
		int idx = BinarySearchS(arr, temp, s, i);
		PrintArr(arr, ARR_LEN); printf(" || value to find : %d --> index : %d\n", temp, idx);
		memmove(arr+idx+1, arr+idx, (i - idx) * sizeof(int));
		arr[idx] = temp;
	}
}

int BinarySearchS(int* arr, int value, int s, int e) {
	if(arr[s] > value) 
		return s;
	int mid;
	while(s <= e) {
		mid = (s + e) / 2;
		if(arr[mid] > value)		e = mid - 1;
		else if(arr[mid] < value)	s = mid + 1;
		else						return mid;
	}
	if (arr[mid] < value)
		return mid + 1;
	else
		return mid;
}