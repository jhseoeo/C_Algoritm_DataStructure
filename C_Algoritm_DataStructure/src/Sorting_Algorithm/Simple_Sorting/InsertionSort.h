/*
Insertion Sort
Time Complexity : O(N^2)
*/

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "../../Base/Base.h"

// Basic Insertion Sort Algorithm.
void InsertionSort(int* arr, int s, int e);

// Improved version of insertion sort. Using binary search, reduces running time.
void BinaryInsertionSort(int* arr, int s, int e);

// Another version to use BinaryInsertionSort. It returns an index of nearest big value. 
int BinarySearchS(int* arr, int value, int s, int e);


#endif