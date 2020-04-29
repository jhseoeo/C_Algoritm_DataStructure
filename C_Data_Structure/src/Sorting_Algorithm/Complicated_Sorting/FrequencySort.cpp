#include "FrequencySort.h"

void FrequencySort(int* arr, int s, int e) {
	
	const int min = 1; // Virtual minimum value of the array.
	const int max = ARR_LEN; // Virtual maximum value of the array.
	
	int* freq = (int*)malloc((max - min + 1) * sizeof(int));
	int* res = (int*)malloc((e - s) * sizeof(int));
	
	for(int i = 0; i < max - min + 1; i++) 	freq[i] = 0;
	for(int i = s; i < e; i++) 				freq[arr[i] - min]++;
	for(int i = s + 1; i < e; i++) 			freq[i] += freq[i-1];
	for(int i = e - s - 1; i >= s; i--) 		res[--freq[arr[i] - min]] = arr[i];
	for(int i = 0; i < e - s; i++)			arr[i + s] = res[i];
	free(freq);	free(res);
}