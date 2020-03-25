#include "Simple_Data_Structure.h"

void Simple_DS() {
	int n;
	system(CLEAR);
	printf("Select the data structure to run\n");
	printf("1. Stack\n");
	printf("2. Queue\n");
	printf("3. Linked Stack\n");
	printf("4. Linked Queue\n");
	printf("5. Deque\n");
	printf(">>> "); scanf("%d", &n); getchar(); printf("\n");
	
	switch(n) {
		case 1:
			Stack_Main();
			break;
		case 2:
			Queue_Main();
			break;
		case 3:
			LinkedStack_Main();
			break;
		case 4:
			LinkedQueue_Main();
			break;
		case 5:
			Deque_Main();
			break;
		default: break;
	}
}