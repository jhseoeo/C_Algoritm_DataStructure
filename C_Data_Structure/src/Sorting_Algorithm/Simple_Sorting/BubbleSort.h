/*
Bubble Sort
Time Complexity : O(N^2)
*/

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "../../Base/Base.h"

// Basic Bubble Sort Algorithm.
void BubbleSort(int* arr, int s, int f);

// Improved version of bubble sort. Reduces running time.
void CocktailSort(int* arr, int s, int f);

#endif