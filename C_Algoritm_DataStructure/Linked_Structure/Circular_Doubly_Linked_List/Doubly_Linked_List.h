/*
	Circular doulby linked list implementation based on pointer.
*/

#ifndef CIRCULAR_DOUBLY_LINKED_LIST
#define CIRCULAR_DOUBLY_LINKED_LIST

#include "../../Base/Base.h"
#include "CdllNode.h"

// Circular doulby linked list implemented by pointer
typedef struct {
	CdllNode* head;
	CdllNode* cur;
} CircularLinkedList;

// Search the value x with function compare
static CdllNode* Search(const CircularLinkedList& list, int x);

// Insert x in the foremost point of list
static void InsertFront(CircularLinkedList* list, int x);

// Insert x in rearest point of list
static void InsertRear(CircularLinkedList* list, int x);

// Delete the node at foremost point of list
static void RemoveFront(CircularLinkedList* list);

// Delete the node at rearest point of list
static void RemoveRear(CircularLinkedList* list);

// Delete the node that pointed by cursor
static void RemoveCursor(CircularLinkedList* list);

// Delete all nodes of list
static void Clear(CircularLinkedList* list);

// Move Cursor of list
static void MoveCur(CircularLinkedList* list, int x);

// Print the value that pointed by cursor of list
static void PrintCur(const CircularLinkedList& list);

// Print the all value of list
static void PrintAll(const CircularLinkedList& list);

// Remove list
static void Terminate(CircularLinkedList* list);

// Make an initialized linear list based on pointer
static CircularLinkedList MakeCircularDoublyLinkedList();


// Main function of linear list implemented by pointer.
void Circular_Doubly_Linked_List_Main();

#endif