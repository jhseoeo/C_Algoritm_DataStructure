#include "ShellSort.h"

// It applies insertion sort to array by an specific interval, and repeat it while reducing interval.
void ShellSort(int* arr, int s, int e) {
	int h = 1;
	for(; h < (e - s) / 9 ; h = h * 3 + 1);
	for(; h > s; h /= 3) {
		for(int j, i = h; i < e; i += h) {
			int temp = arr[i];
			for(j = i; j > s && arr[j - h] > temp; j -= h) {
				arr[j] = arr[j-h];
			}
			arr[j] = temp;
		}
	}	
}