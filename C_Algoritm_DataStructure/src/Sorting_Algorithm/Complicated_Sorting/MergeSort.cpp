#include "MergeSort.h"

void MergeSort(int* arr, int s, int e) {
	if(e > s) {
		int mid = (s + e) / 2;
		MergeSort(arr, s, mid);	
		MergeSort(arr, mid + 1, e);				// Divide array into two parts.
		int p = s, q = mid + 1, i = 0;
		int* temp = (int*) malloc((e - s + 1) * sizeof(int));
		while(true) {							// Merge two array
			if(p > mid && q > e) 			break;
			else if(p > mid != q > e)		temp[i++] = (p > mid ? arr[q++] : arr[p++]);
			else if(arr[p] > arr[q])		temp[i++] = arr[q++];
			else							temp[i++] = arr[p++];
		}
		for(int j = 0; j < i; j++) 
			arr[j + s] = temp[j];				// Copy temporary array into existing array.
		
		free(temp);
	}	
}