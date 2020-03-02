/*
This container is for algorithms and data structures
*/

#include "./Search_Algorithm/Search_Algorithm.h"
#include "./Recursion_Algorithm/Recursion_Algorithm.h"
#include "./Sorting_Algorithm/Sorting_Algorithm.h"
#include "./Simple_Data_Structure/Simple_Data_Structure.h"
#include "./Practical_Data_Structure/Practical_Data_Structure.h"
#include "./Linked_Structure/Linked_Structure.h"

// Main function that tests many kind of searching/sorting algorithms and data structures.
int main(void) {
	system(CLEAR);
	printf("Enter the algorithm list to run\n");
	printf("1. Search Algorithm\n");
	printf("2. Recursion Algorithm\n");
	printf("3. Sorting Algorithm\n");
	printf("4. Simple Data Structure ( Stack, Queue )\n");
	printf("5. Practical Data Structure ( Set, String )\n");
	printf("6. Linked Structure\n");
	printf(">> "); 
	int n; scanf("%d", &n); getchar(); printf("\n");

	switch(n) {
		case 1:
			Search_Algorithm();
			break;
		case 2:
			Recursion_Algorithm();
			break;
		case 3:
			Sorting_Algorithm();
			break;
		case 4:
			Simple_DS();
			break;
		case 5:
			Practical_DS();
			break;
		case 6:
			Linked_Structure();
			break;
		default:
			break;
	}
	
	return 0;
}		