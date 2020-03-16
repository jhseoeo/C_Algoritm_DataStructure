/*
	Chain Hashing. Store the data that has same hash value in linked list.
*/

#include "../../Base/Base.h"

#ifndef CHAIN_HASHING_H
#define CHAIN_HASHING_H


#define EMPTY -1	// symbol of empty value.

// Node that represents individual bukkit.
typedef struct __node {
	Data data;
	struct __node* next;
} CHNode;

// Allocate new CHNode
static CHNode* MakeCHNode();

// Set values of CHNode
static void SetCHNode(CHNode* node, Data data, CHNode* next);

// Hash Table implemented in Chain Hashing.
typedef struct {
	int size;
	CHNode** Table;
} ChainHash;

// Hash function
static int Hash(Data data, int size);

// Search the value from hash table. If there is node that has same value with parameter, return the address of node. Otherwise return NULL.
static CHNode* Search(const ChainHash* h, Data data);

// Add the new node that has same data with parameter. If there already is, do not execte it.
static int Add(ChainHash* h, Data data);

// Remove node that has same data with parameter. 
static int Remove(ChainHash* h, Data data);

// Print all contents of Hash Table.
static void Dump(const ChainHash* h);

// Clear all elements of Hash Table.
static void Clear(ChainHash* h);

// Make new Chain hash table and return it.
static ChainHash MakeChainHash(int size);

#endif