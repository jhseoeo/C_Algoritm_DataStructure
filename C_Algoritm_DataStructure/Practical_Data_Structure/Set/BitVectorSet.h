/*
	Set implemented by bit vector.
*/

#include "../../Base/Base.h"

#ifndef BITVECTORSET_H
#define BITVECTORSET_H

//Set implemented by bit vector.
typedef unsigned long BitSet;

// Empty set
#define BitSetNull (BitSet)0

// Maximum capacity of set
#define BitSetMax 31

// Minimum capacity of set
#define BitSetMin 0

// Make a set that has only element no
#define SetOf(no) ((BitSet)1 <<(no))


// check if n is in proper value range
static int CheckSize(int n);	

// check if n is member of ss
static int IsMember(const BitSet &s, int n);	

// Add n into s
static void Add(BitSet* s, int n);	

// Remove n from s
static void Remove(BitSet* s, int n);	

// Return size of s
static int Size(const BitSet &s);	

// print all value of s
static void Print(const BitSet &s);	

// check if s1 is same with s2
static int Equal(const BitSet &s1, const BitSet &s2);	

// return the union of s2 and s3 into s1
static BitSet Union(const BitSet &s1, const BitSet &s2);	

// return the intersection of s2 and s3 into s1
static BitSet Intersection(const BitSet &s1, const BitSet &s2);	

// return s2 difference s3 into s1
static BitSet Difference(const BitSet &s1, const BitSet &s2);	

// Make initialized bitset
static BitSet MakeBitSet();	

// Check if s2 is subset of s1
static int IsSubset(const BitSet &s1, const BitSet &s2);

// return the symmetric difference of s1 and s2
static BitSet SymmetricDifference(const BitSet& s1, const BitSet& s2);

// temporary
static void GetSetNum(int& i);

// Main function of set implemented by bit vector
void BitVectorSetMain();

#endif