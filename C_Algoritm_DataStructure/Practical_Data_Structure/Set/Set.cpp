#include "Set.h"

void Set_Main() {
	int n;
	system("cls");
	printf("Choose the type of set to run\n");
	printf("1. List-based set.\n");
	printf(">> "); 	scanf("%d", &n); getchar(); printf("\n");
	
	switch(n) {
		case 1:
			ListSetMain();
	}
}