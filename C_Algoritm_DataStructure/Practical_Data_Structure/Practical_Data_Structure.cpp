#include "Practical_Data_Structure.h"

void Practical_DS() {
	int n;
	system("cls");
	printf("Select the data structure to run\n");
	printf("1. Set\n");
	printf(">>> "); scanf("%d", &n);
	
	switch(n) {
		case 1:
			Set_Main();
			break;
	}
}
