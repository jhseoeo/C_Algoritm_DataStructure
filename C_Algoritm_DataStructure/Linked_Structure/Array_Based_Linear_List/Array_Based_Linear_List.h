/*
	Linked list implementation based on pointer.
*/

#ifndef ARRAY_BASED_LINEAR_LIST
#define ARRAY_BASED_LINEAR_LIST

#include "../../Base/Base.h"
#include "AllNode.h"

#define SIZE 10

typedef struct {
	AllNode* n;		// Array of nodes.
	Index Head;		// First index of used nodes.
	Index deleted;	// First index of deleted nodes.
	Index cur;		// cursor that can be used for an amounts of ways.
} Arr_LinearList;

// Search the value x with function compare
static Index Search(Arr_LinearList* list, Data x);

// Insert x in the foremost point of list
static void InsertFront(Arr_LinearList* list, Data x);

// Insert x in rearest point of list
static void InsertRear(Arr_LinearList* list, Data x);

// Delete the node at foremost point of list
static void RemoveFront(Arr_LinearList* list);

// Delete the node at rearest point of list
static void RemoveRear(Arr_LinearList* list);

// Delete the node that pointed by cursor
static void RemoveCursor(Arr_LinearList* list);

// Delete all nodes of list
static void Clear(Arr_LinearList* list);

// Move Cursor of list
static void MoveCur(Arr_LinearList* list, Data x);

// Print the value that pointed by cursor of list
static void PrintCur(const Arr_LinearList& list);

// Print the all value of list
static void PrintAll(const Arr_LinearList& list);

// Remove list
static void Terminate(Arr_LinearList* list);

// Make an initialized linear list based on pointer
static Arr_LinearList MakeArrLinearList();

// Main function of linear list implemented by array.
void Array_Based_Linear_List_Main();

#endif