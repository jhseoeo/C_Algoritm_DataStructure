#include "Sorting_Algorithm.h"

void Sorting_Algorithm() {
	int* a;

	int n;

	while(1) {
		a = makeRandArr();

		system(CLEAR);
		printf("Select the sorting algorithm to run\n");
		printf("1. Bubble Sort\n");
		printf("11. Cocktail Sort(Improved Bubble Sort)\n");
		printf("2. Selection Sort\n");
		printf("3. Insertion Sort\n");
		printf("31. Binary Insertion Sort(Improved Insertion Sort)\n");
		printf("4. Shell Sort(Improved Insertion Sort)\n");
		printf("5. Quick Sort\n");
		printf("6. Merge Sort\n");
		printf("7. Heap Sort\n");
		printf("8. Frequency Sort\n");
		printf(">>> "); scanf("%d", &n); getchar(); printf("\n");

		printf("BEFORE SORT : ");
		PrintArr(a, ARR_LEN);

		switch(n) {
			case 1:
				BubbleSort(a, 0, ARR_LEN);
				printf("###### Bubble Sort ######\n");
				break;
			case 11:
				CocktailSort(a, 0, ARR_LEN);
				printf("###### Cocktail Sort ######\n");
				break;
			case 2:
				printf("###### Selection Sort ######\n");
				SelectionSort(a, 0, ARR_LEN);
				break;
			case 3:
				printf("###### Insertion Sort ######\n");
				InsertionSort(a, 0, ARR_LEN);
				break;
			case 31:
				printf("###### Binary Insertion Sort ######\n");
				BinaryInsertionSort(a, 0, ARR_LEN);
				break;
			case 4:
				printf("###### Shell Sort ######\n");
				ShellSort(a, 0, ARR_LEN);
				break;
			case 5:
				printf("###### Quick Sort ######\n");
				QuickSort(a, 0, ARR_LEN - 1);
//				QuickSort2(a, ARR_LEN - 1);
				break;
			case 6:
				printf("###### Merge Sort ######\n");
				MergeSort(a, 0, ARR_LEN - 1);
				break;
			case 7:
				printf("###### Heap Sort ######\n");
				HeapSort(a, 0, ARR_LEN - 1);
				break;
			case 8:
				printf("###### Frequency Sort ######\n");
				FrequencySort(a, 0, ARR_LEN);
				break;
			default:
				break;
		}

		printf("AFTER SORT  : ");
		PrintArr(a, ARR_LEN);
		sleep(1500);
		
					RUNAGAIN:
		printf("run again? (Y/N)\n");
		printf(">>> "); n = getchar(); getchar(); printf("\n");
		
		if(n == 'Y' || n == 'y') {
			free(a);
			continue;
		} else if (n == 'N' || n == 'n') {
			break;
		} else {
			goto RUNAGAIN;
		}
	}

	free(a);
	return;
}