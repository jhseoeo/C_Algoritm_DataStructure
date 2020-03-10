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

// check if n is member of s
static int isMember(const ListSet *s, Data n);

// Add n into s
static void Add(ListSet *s, Data n);

// Remove n from s
static void Remove(ListSet *s, Data n);

// get the size of s
static int Size(const ListSet* s);	

// assign s2 into s1 
static void Assign(ListSet* s1, const ListSet* s2);

// check if s1 is same with s2
static int Equal(const ListSet* s1, const ListSet* s2);	

// assign the union of s2 and s3 into s1
static ListSet* Union(ListSet* s1, const ListSet* s2, const ListSet* s3);	

// assign the intersection of s2 and s3 into s1
static ListSet* Intersection(ListSet* s1, const ListSet* s2, const ListSet* s3);	

// assign s2 difference s3 into s1
static ListSet* Difference(ListSet* s1, const ListSet* s2, const ListSet* s3);	

// print all value of s
static void Print(const ListSet* s);	

// remove s
static void Terminate(ListSet* s);	

// Make an initialized ListSet.
static ListSet MakeListSet(int size); 

// return the symmetric difference of s1 and s2
static ListSet* SymmetricDifference(ListSet* s1, const ListSet* s2, const ListSet* s3);

// Check if s2 is subset of s1
static int IsSubset(const ListSet* s1, const ListSet* s2);


// temorary
static void GetSetNum(int& i);

// Main function of set implemented by array
void ListSetMain();

#endif