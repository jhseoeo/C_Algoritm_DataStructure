/*
	Simple data structure Queue implemented by linked list and a series of associated functions.
*/

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "../../Base/Base.h"
#include "./LinkedQueueNode.h"

// Queue. It has attribute of First In First Out. Implemented by linked list.
typedef struct {
	LqueueNode* front;	// Pointer of the foremost node of queue.
	LqueueNode* rear;	// Pointer of the rearest node of queue.
	int size;
} LinkedQueue;

// Enque the value to queue.
static int Enque(LinkedQueue* que, Data value);

// Deque the value from queue.
static int Deque(LinkedQueue* que, Data* value);

// See the value of rearest point of queue.
static int Peek(const LinkedQueue* que, Data* value);

// Clear the all value from queue.
static void Clear(LinkedQueue* que);

// See the current size of queue.
static int Size(const LinkedQueue* que);

// See if the queue is empty.
static int isEmpty(const LinkedQueue* que);

// Search the given value from queue. 
static int Search(const LinkedQueue* que, Data value);

// Print out all the value of queue.
static void Print(const LinkedQueue* que);

// Delete the queue and all the contents of it.
static void Terminate(LinkedQueue* que);

// Make an initialized stack.
static LinkedQueue MakeLinkedQueue();


// The main function to test linked queue.
void LinkedQueue_Main();

#endif