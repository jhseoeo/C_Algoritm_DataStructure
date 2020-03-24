/*
	Simple data structure stack implemented by linked list and a series of associated functions.
*/

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "../../Base/Base.h"
#include "./LinkedStackNode.h"

// // Stack. It has attribute of Last In First Out. Implemented by linked list.
typedef struct {
	LstackNode* stk;	// Pointer of the top node of stack.
	int size;
} LinkedStack;

// Push value to stack.
static int Push(LinkedStack* stack, Data value);

// Pop value from stack.
static int Pop(LinkedStack* stack, Data* value);

// See the value of Stack's highest point.
static int Peek(const LinkedStack* stack, Data* value);

// Clear the all value from stack.
static void Clear(LinkedStack* stack);

// See if the stack is empty.
static int isEmpty(const LinkedStack* stack);

// Search the given value from stack. 
static int Search(const LinkedStack* stack, Data value);

// Print out the all value of stack.
static void Print(const LinkedStack* stack);

// Delete the stack and all the contents of it.
static void Terminate(LinkedStack* stack);

// Make an initialized stack.
static LinkedStack MakeLinkedStack();


// The main function to test stack.
void LinkedStack_Main();

#endif