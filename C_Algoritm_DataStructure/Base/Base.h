/*
A series of function and libraries that being needed to learn algorithms.
*/

#ifndef BASE_H
#define BASE_H

#define _CRT_SECURE_NO_WARNINGS

const int ARR_LEN = 9;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#if defined(_WIN32) || defined(_WIN64)
	#include <Windows.h>
	#define sleep(X) Sleep(X)
#elif defined(__linux)
#endif



// Change two values of variables by passing py reference.
void swap(int &a, int &b);
	
// Making an array of rand number. Numbers do not duplicate.
int* makeRandArr();

// Making an array of sorted number. Numbers are sorted by ascending order.
int* makeSortedArr();

// Print an array;
void PrintArr(int* arr, int n);

#endif