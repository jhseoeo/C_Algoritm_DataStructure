#include "Recursion_Algorithm.h"
#include "Five_Queen_Problem.h"

void Recursion_Algorithm(int (*prev)()) {
	int n;
	system("cls");
	printf("Select the algorithm to run\n");
	printf("1. 5-Queen Problem\n");
	printf("0. prev\n");
	printf(">>> "); scanf("%d", &n); getchar();
	
	switch(n) {
		case 1:
			Five_Queen_Problem();
			break;
		case 0:
			(*prev)();
			break;
		default: break;
	}
}

