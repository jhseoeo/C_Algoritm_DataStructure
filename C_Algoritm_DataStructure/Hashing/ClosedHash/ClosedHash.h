/*
	Chain Hashing. Rehash when the collision occured.
*/

#include "../../Base/Base.h"

#ifndef CLOSEDHASH_H
#define CLOSEDHASH_H

// Status to express each node of closed hash table.
enum Status {
	OCCUPIED, EMPTHY, DELETED
};

// 
typedef struct {
	Status status;
	Data data;
} ClosedNode;

static ClosedNode SetNode(Status status, Data data);

// Hash Table implemented in Closed Hashing.
typedef struct {
	int size;
	ClosedNode* Table;
} ClosedHash;

// Hash function
static int Hash(Data data, int size);

// Search the value from hash table. If there is node that has same value with parameter, return the address of node. Otherwise return NULL.
static ClosedNode* Search(const ClosedHash* h, Data data);

// Add the new node that has same data with parameter. If there already is, do not execte it.
static int Add(ClosedHash* h, Data data);

// Remove node that has same data with parameter. 
static int Remove(ClosedHash* h, Data data);

// Print all contents of Hash Table.
static void Dump(const ClosedHash* h);

// Clear all elements of Hash Table.
static void Clear(ClosedHash* h);

// Remove Hash Table.
static void Terminate(ClosedHash* h);

// Make new Closed hash table and return it.
static ClosedHash MakeClosedHash(int size);

// Main function of Hashing implemented Closed Hashing.
void ClosedHashMain();

#endif