#include "Linked_Structure.h"

void Linked_Structure() {
	int n;
	system(CLEAR);
	printf("Select the data structure to run\n");
	printf("1. Pointer Based Linear List\n");
	printf(">>> "); scanf("%d", &n); getchar(); printf("\n");

	switch (n) {
	case 1:
		Pointer_Based_Linear_List_Main();
		break;
	default: break;
	}
}