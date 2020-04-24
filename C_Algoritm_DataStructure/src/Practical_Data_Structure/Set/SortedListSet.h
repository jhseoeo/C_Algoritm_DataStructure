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

// check if n is member of s
static int isMember(const SortedListSet* s, Data n);

// Add n into s
static void Add(SortedListSet* s, Data n);

// Remove n from s
static void Remove(SortedListSet* s, Data n);

// get the size of s
static int Size(const SortedListSet* s);	

// assign s2 into s1 
static void Assign(SortedListSet* s1, const SortedListSet* s2);	

// check if s1 is same with s2
static int Equal(const SortedListSet* s1, const SortedListSet* s2);	

// assign the union of s2 and s3 into s1
static SortedListSet* Union(SortedListSet* s1, const SortedListSet* s2, const SortedListSet* s3);	

// assign the intersection of s2 and s3 into s1
static SortedListSet* Intersection(SortedListSet* s1, const SortedListSet* s2, const SortedListSet* s3);	

// assign s2 difference s3 into s1
static SortedListSet* Difference(SortedListSet* s1, const SortedListSet* s2, const SortedListSet* s3);	

// print all value of s
static void Print(const SortedListSet* s);	

// remove s
static void Terminate(SortedListSet* s);	

// Make an initialized SortedListSet.
static SortedListSet MakeSortedListSet(int size); 

// return the symmetric difference of s1 and s2
static SortedListSet* SymmetricDifference(SortedListSet* s1, const SortedListSet* s2, const SortedListSet* s3);

// Check if s2 is subset of s1
static int IsSubset(const SortedListSet* s1, const SortedListSet* s2);

// temporary
static void GetSetNum(int &i);

// Main function of set implemented by sorted list
void SortedListSetMain();

#endif