/*
	Set implemented by bit vector.
*/

#include "../../Base/Base.h"

#ifndef BITVECTORSET_H
#define BITVECTORSET_H

typedef unsigned long BitSet;

#define BitSetNull (BitSet)0
#define BitSetMax 31
#define BitSetMin 0
#define SetOf(no) ((BitSet)1 <<(no))

static int CheckSize(int n);	// check if n is in proper value range
static int IsMember(const BitSet &s, int n);	// check if n is member of ss
static void Add(BitSet* s, int n);	// Add n into s
static void Remove(BitSet* s, int n);	// Remove n from s
static int Size(const BitSet &s);	// Return size of s
static void Print(const BitSet &s);	// print all value of s
static int Equal(const BitSet &s1, const BitSet &s2);	// check if s1 is same with s2
static BitSet Union(const BitSet &s1, const BitSet &s2);	// return the union of s2 and s3 into s1
static BitSet Intersection(const BitSet &s1, const BitSet &s2);	// return the intersection of s2 and s3 into s1
static BitSet Difference(const BitSet &s1, const BitSet &s2);	// return s2 difference s3 into s1
static BitSet MakeBitSet();	// Make initialized bitset

static int IsSubset(const BitSet &s1, const BitSet &s2);
static BitSet SymmetricDifference(const BitSet& s1, const BitSet& s2);

static void GetSetNum(int& i);
void BitVectorSetMain();

#endif