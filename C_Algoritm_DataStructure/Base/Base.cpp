#include "Base.h"

void swap(int &a, int &b) {
	int temp = b;
	b = a;
	a = temp;
}

int* makeRandArr() {
	int* a = (int*)malloc(ARR_LEN * sizeof(int));
	srand((unsigned int)time(NULL));
	
	for(int i = 0; i < ARR_LEN; i++) {
RESET:
		a[i] = rand() % ARR_LEN + 1;
		for(int j = 0; j < i; j++) {
			if(a[i] == a[j])
				goto RESET;
		}
	}
	return a;
}

int* makeSortedArr() {
	int* b = (int*)malloc(ARR_LEN * sizeof(int));
	for(int i = 0; i < ARR_LEN; i++)
		b[i] = i+1;
	return b;
}

void PrintArr(int* arr, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", arr[i]);	
	}
	printf("\n");
}