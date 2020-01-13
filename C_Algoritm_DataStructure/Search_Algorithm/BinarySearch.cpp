#include "BinarySearch.h"

int BinarySearch(int v, const int* a, int n) {
	
	int min = 0, max = n - 1;
	while(min <= max) {
		int mid = (min + max) / 2;
		
		if (a[mid] < v)
			min = mid + 1;
		else if (a[mid] > v)
			max = mid - 1;
		else 
			return mid;
	}
	return -1;
}

int BinarySearchS(int v, const int* a, int n) {

	int min = 0, max = n - 1, mid = -1;
	while (min <= max) {
		mid = (min + max) / 2;

		if (a[mid] < v)
			min = mid + 1;
		else if (a[mid] > v)
			max = mid - 1;
		else
			return mid;
	}
	return mid;
}