#include "Tree.h"

void Tree_Main() {
	int n;
	system(CLEAR);
	printf("Select the data structure to run\n");
	printf("1. Binary Search Tree\n");
	printf(">>> "); scanf("%d", &n); getchar(); printf("\n");

	switch (n) {
	case 1:
		Binary_Search_Tree_Main();
		break;
	default: break;
	}
	return;
}