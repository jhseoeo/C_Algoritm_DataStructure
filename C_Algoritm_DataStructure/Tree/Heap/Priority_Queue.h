/*
	Priority Queue implemented by heap and a series of associated functions.
*/

#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include "../../Base/Base.h"
#include "Heap.h"

// Queue. It has attribute of First In First Out. And has circular architecture.
typedef struct {
	Heap heap;
} PriorityQueue;

// Enque the value to queue.
static int Enque(PriorityQueue* que, Data value);

// Deque the value from queue.
static int Deque(PriorityQueue* que, Data* value);

// See the value of rearest point of queue.
static int Peek(const PriorityQueue* que, Data* value);

// Clear the all value from queue.
static void Clear(PriorityQueue* que);

// See the current size of queue.
static int Size(const PriorityQueue* que);

// See if the queue is empty.
static int isEmpty(const PriorityQueue* que);

// See if the queue is full.
static int isFull(const PriorityQueue* que);

// Print the conents of priority queue.
static void Print(const PriorityQueue* que);

// Delete the queue and all the contents of it.
static void Terminate(PriorityQueue* que);

// Make an initialized queue.
static PriorityQueue MakePriorityQueue(int size);

// The main function to test queue.
void PriorityQueue_Main();

#endif