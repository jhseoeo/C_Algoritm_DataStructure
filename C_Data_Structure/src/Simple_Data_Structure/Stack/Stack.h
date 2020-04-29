/*
	Simple data structure stack implemented by array and a series of associated functions.
*/

#ifndef STACK_H
#define STACK_H

#include "../../Base/Base.h"

// Stack. It has attribute of Last In First Out. Implemented by array.
typedef struct {
	int max;	// The number of maximum elements of stack.
	int idx;	// Index of arr that points out top element of stack.
	Data* stk;	// Allocated stack array.
} Stack;


// Push value to stack.
static int Push(Stack *stack, Data value);

// Pop value from stack.
static int Pop(Stack *stack, Data* value);

// See the value of Stack's highest point.
static int Peek(const Stack *stack, Data* value);

// Clear the all value from stack.
static void Clear(Stack *stack); 

// See if the stack is empty.
static int isEmpty(const Stack *stack);

// See if the stack is full.
static int isFull(const Stack *stack);

// Search the given value from stack. 
static int Search(const Stack *stack, Data value);

// Print out the all value of stack.
static void Print(const Stack *stack);

// Delete the stack and all the contents of it.
static void Terminate(Stack *stack);

// Make an initialized stack.
static Stack MakeStack(int size); 


// The main function to test stack.
void Stack_Main();

#endif