#include "Practical_Data_Structure.h"

void Practical_DS() {
	int n;
	system(CLEAR);
	printf("Select the data structure to run\n");
	printf("1. Set\n");
	printf("2. String\n");
	printf(">>> "); scanf("%d", &n);
	
	switch(n) {
		case 1:
			Set_Main();
			break;
		case 2:
			String_Main();
			break;
		default: break;
	}
}
