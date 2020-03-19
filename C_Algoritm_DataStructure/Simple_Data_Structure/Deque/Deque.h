/*
	Deque and a series of associated functions.
*/

#ifndef DEQUE_H
#define DEQUE_H

#include "../../Base/Base.h"
#include "./DequeNode.h"

// 
typedef struct {
	DequeNode* front;
	DequeNode* rear;
	DequeNode* cursor;
} Deque;



#endif