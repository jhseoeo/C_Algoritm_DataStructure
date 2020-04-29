#include "Set.h"

void Set_Main() {
	int n;
	system(CLEAR);
	printf("Choose the type of set to run\n");
	printf("1. List-based set.\n");
	printf("2. SortedList-based set.\n");
	printf("3. BitVector-based Set\n");
	printf(">> "); 	scanf("%d", &n); getchar(); printf("\n");
	
	switch(n) {
		case 1:
			ListSetMain();
			break;
		case 2:
			SortedListSetMain();
			break;
		case 3:
			BitVectorSetMain();
			break;
		default: break;
	}
}