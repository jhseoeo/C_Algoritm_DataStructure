#include "Hashing.h"

void Hashing_Main() {
	int n;
	system(CLEAR);
	printf("Select the type of hashing\n");
	printf("1. Chain Hashing\n");
	printf("2. Closed Hashing\n");
	printf(">>> "); scanf("%d", &n);

	switch (n) {
	case 1:
		ChainHashMain();
		break;
	case 2:
		ClosedHashMain();
		break;
	default: break;
	}
}