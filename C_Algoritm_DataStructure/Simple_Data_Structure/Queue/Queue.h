/*
Simple data structure Queue and a series of associated functions.
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "../../Base/Base.h"

// Stack. It has attribute of First In First Out.
typedef struct {
	int front;
	int rear;
	int max;
	int* queue;
} Queue;

// Enque the value to queue.
static int Enque(Queue *que, int value); 

// Deque the value from queue.
static int Deque(Queue *que, int* value);

// See the value of rearest point of queue.
static int Peek(const Queue *que, int* value);

// Clear the all value from queue.
static void Clear(Queue *que); 

// See the current size of queue.
static int Size(const Queue *que); 

// See if the queue is empty.
static int isEmpty(const Queue *que); 

// See if the queue is full.
static int isFull(const Queue *que); 

// Search the given value from queue. 
static int Search(const Queue *que, int value);

// Print out all the value of queue.
static void Print(const Queue *que);

// Delete the queue and all the contents of it.
static void Terminate(Queue *que); 

// Make an initialized stack.
static Queue MakeQueue(int size); 


// The main function to test stack.
void Queue_Main(); 

#endif