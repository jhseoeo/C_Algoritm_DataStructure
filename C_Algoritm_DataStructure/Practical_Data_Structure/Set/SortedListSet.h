/*
Set implemented by SORTED list and a series of associated functions.
*/

#ifndef SORTEDLISTSET_H
#define SORTEDLISTSET_H

#include "../../Base/Base.h"
#include "../../Search_Algorithm/BinarySearch.h"

// Set implemented by using SORTED list.
typedef struct {
	int max;	// maximum number of value
	int size;	// current number of value
	int* set; 	// array
} SortedListSet;

static int isMember(const SortedListSet* s, int n);	// check if n is member of s
static void Add(SortedListSet* s, int n);	// Add n into s
static void Remove(SortedListSet* s, int n);	// Remove n from s
static int Size(const SortedListSet* s);	// get the size of s
static void Assign(SortedListSet* s1, const SortedListSet* s2);	// assign s2 into s1 
static int Equal(const SortedListSet* s1, const SortedListSet* s2);	// check if s1 is same with s2
static SortedListSet* Union(SortedListSet* s1, const SortedListSet* s2, const SortedListSet* s3);	// assign the union of s2 and s3 into s1
static SortedListSet* Intersection(SortedListSet* s1, const SortedListSet* s2, const SortedListSet* s3);	// assign the intersection of s2 and s3 into s1
static SortedListSet* Difference(SortedListSet* s1, const SortedListSet* s2, const SortedListSet* s3);	// assign s2 difference s3 into s1
static void Print(const SortedListSet* s);	// print all value of s
static void Terminate(SortedListSet* s);	// remove s
static SortedListSet MakeSortedListSet(int size); // Make an initialized  ListSet.

static SortedListSet* SymmetricDifference(SortedListSet* s1, const SortedListSet* s2, const SortedListSet* s3);
static int IsSubset(const SortedListSet* s1, const SortedListSet* s2);

static void GetSetNum(int& i);
void SortedListSetMain();

#endif