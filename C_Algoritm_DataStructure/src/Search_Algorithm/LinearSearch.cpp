#include "BinarySearch.h"

int LinearSearch(int v, const int* a, int n) {
	
	for(int i = 0; i < n; i++)
		if (a[i] == v)
			return i;
	return -1;
}