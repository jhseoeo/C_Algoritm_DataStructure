/*
Set implemented by list and a series of associated functions.
*/

#ifndef LISTSET_H
#define LISTSET_H

#include "../../Base/Base.h"

// Set implemented by using list.
typedef struct {
	int max;	// maximum number of value
	int size;	// current number of value
	int* set; 	// array
} ListSet;

static int isMember(const ListSet *s, int n);	// check if n is member of s
static void Add(ListSet *s, int n);	// Add n into s
static void Remove(ListSet *s, int n);	// Remove n from s
static int Size(const ListSet* s);	// get the size of s
static void Assign(ListSet* s1, const ListSet* s2);	// assign s2 into s1 
static int Equal(const ListSet* s1, const ListSet* s2);	// check if s1 is same with s2
static ListSet* Union(ListSet* s1, const ListSet* s2, const ListSet* s3);	// assign the union of s2 and s3 into s1
static ListSet* Intersection(ListSet* s1, const ListSet* s2, const ListSet* s3);	// assign the intersection of s2 and s3 into s1
static ListSet* Difference(ListSet* s1, const ListSet* s2, const ListSet* s3);	// assign s2 difference s3 into s1
static void Print(const ListSet* s);	// print all value of s
static void Terminate(ListSet* s);	// remove s
static ListSet MakeListSet(int size); // Make an initialized ListSet.

static ListSet* SymmetricDifference(ListSet* s1, const ListSet* s2, const ListSet* s3);
static int IsSubset(const ListSet* s1, const ListSet* s2);

static void GetSetNum(int& i);
void ListSetMain();

#endif