#include "Search_Algorithm.h"

void Search_Algorithm(int (*prev)()) {
	while(1) {
		int* a = makeRandArr();
		int* b = makeSortedArr();
		int* c = 0;

		system("cls");
		printf("a : ");
		PrintArr(a, ARR_LEN);
		printf("b : ");
		PrintArr(b, ARR_LEN);
	
		printf("\nEnter the array name that you use\n");
		printf("Enter p to go prev page\n");
		printf(">> "); char arrName = getchar();
	
		switch(arrName) {
			case 'a':
				c = a;
				break;
			case 'b':
				c = b;
				break;
			case 'p':
				(*prev)();
			default: break;
		}
	
		printf("\nEnter the number that you want to find\n");
		printf(">> "); int v; scanf("%d", &v); getchar();
	
		printf("\nSelect the Search Algorithm\n");
		printf("1. Linear Search\n");
		printf("2. Binary Search\n");
		printf("3. Binary Search S\n");
		printf("...\n");
		printf(">> "); int n; scanf("%d", &n); getchar();
	
		int idx = 0;
		switch(n) {
			case 1:
				idx = LinearSearch(v, c, ARR_LEN);
				break;
			case 2:
				idx = BinarySearch(v, c, ARR_LEN);	
				break;
			case 3:
				idx = BinarySearchS(v, c, ARR_LEN);
				break;
			default: break;
		}
	
		printf("\nIndex of number : %d\n", idx);
		free(a);
		free(b);

		printf("\n1 : Try again\n");
		printf("2 : End\n");
		printf(">> "); n; scanf("%d", &n); getchar();
		if (n == 2) break;
	}
}

