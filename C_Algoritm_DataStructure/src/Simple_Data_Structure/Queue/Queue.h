/*
	Simple data structure Queue implemented by array and a series of associated functions.
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "../../Base/Base.h"

// Queue. It has attribute of First In First Out. And has circular architecture.
typedef struct {
	int front;	// Index of arr that points out foremost element of queue.
	int rear;	// Index of arr that points out rearest element of queue.
	int max;	// The number of maximum elements of queue.
	Data* queue;	// Allocated queue array.
} Queue;

// Enque the value to queue.
static int Enque(Queue *que, Data value);

// Deque the value from queue.
static int Deque(Queue *que, Data* value);

// See the value of rearest point of queue.
static int Peek(const Queue *que, Data* value);

// Clear the all value from queue.
static void Clear(Queue *que); 

// See the current size of queue.
static int Size(const Queue *que); 

// See if the queue is empty.
static int isEmpty(const Queue *que); 

// See if the queue is full.
static int isFull(const Queue *que); 

// Search the given value from queue. 
static int Search(const Queue *que, Data value);

// Print out all the value of queue.
static void Print(const Queue *que);

// Delete the queue and all the contents of it.
static void Terminate(Queue *que); 

// Make an initialized queue.
static Queue MakeQueue(int size); 


// The main function to test queue.
void Queue_Main(); 


Queue MakeQueue_q(int size);
int Enque_q(Queue* que, Data value);
int Deque_q(Queue* que, Data* value);
void Terminate_q(Queue* que);

#endif