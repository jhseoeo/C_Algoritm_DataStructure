#include "Simple_Data_Structure.h"

void Simple_DS() {
	int n;
	system("cls");
	printf("Select the data structure to run\n");
	printf("1. Stack\n");
	printf("2. Queue\n");
	printf(">>> "); scanf("%d", &n);
	
	switch(n) {
		case 1:
			Stack_Main();
			break;
		case 2:
			Queue_Main();
			break;
		default: break;
	}
}