/*
a series of binary search algoritms.
*/

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include "../Base/Base.h"

// Basic binary search. only works on sorted(ascending order) array.
int BinarySearch(int v, const int* a, int n);
int BinarySearchS(int v, const int* a, int n);

#endif