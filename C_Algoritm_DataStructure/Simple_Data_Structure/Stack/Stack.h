/*
Simple data structure stack and a series of associated functions.
*/

#ifndef STACK_H
#define STACK_H

#include "../../Base/Base.h"

// Stack. Last In First Out.
typedef struct {
	int max;
	int idx;
	int* stk;
} Stack;

static int Push(Stack *stack, int value); // Push value to stack.
static int Pop(Stack *stack, int* value); // Pop value from stack.
static int Peek(const Stack *stack, int* value); // See the value of Stack's highest point.
static void Clear(Stack *stack); // Clear the all value from stack.
static int isEmpty(const Stack *stack); // See if the stack is empty.
static int isFull(const Stack *stack); // See if the stack is full.
static int Search(const Stack *stack, int value); // Search the given value from stack. 
static void Print(const Stack *stack); // Print out the all value of stack.
static void Terminate(Stack *stack); // Delete the stack and all the contents of it.
static Stack MakeStack(int size); // Make an initialized stack.

void Stack_Main(); // The main function to test stack.

#endif