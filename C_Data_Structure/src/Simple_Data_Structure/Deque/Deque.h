/*
	Deque and a series of associated functions.
*/

#ifndef DEQUE_H
#define DEQUE_H

#include "../../Base/Base.h"
#include "./DequeNode.h"

// Deque and a series of associated functions. Deque is able to add data in both of front and rear.
typedef struct {
	DequeNode* front;	// Pointer of the foremost node of deque.
	DequeNode* rear;	// Pointer of the rearest node of deque.
	int size;
} Dequez;

// Add the value into front of deque.
static int AddFront(Dequez* que, Data value);

// Add the value into rear of deque.
static int AddRear(Dequez* que, Data value);

// Remove the value from front of queue.
static int RemoveFront(Dequez* que, Data* value);

// Remove the value from rear of queue.
static int RemoveRear(Dequez* que, Data* value);

// Clear the all value from deque.
static void Clear(Dequez* que);

// See the current size of deque.
static int Size(const Dequez* que);

// See if the deque is empty.
static int isEmpty(const Dequez* que);

// Search the given value from deque. 
static int Search(const Dequez* que, Data value);

// Print out all the value of deque.
static void Print(const Dequez* que);

// Delete the deque and all of its contents.
static void Terminate(Dequez* que);

// Make an initialized deque.
static Dequez MakeDeque(int size);

// The main function to test linked queue.
void Deque_Main();

#endif