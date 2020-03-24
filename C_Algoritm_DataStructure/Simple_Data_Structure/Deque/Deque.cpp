#include "Deque.h"

static int AddFront(Deque* que, Data value) {
	DequeNode* node = AllocDequeNode();
	if (que->front == NULL) {
		SetDequeNode(node, NULL, NULL, value);
		que->front = que->rear = node;
	} else {
		SetDequeNode(node, que->front, NULL, value);
		que->front->prev = node;
		que->front = node;
	}
	que->size++;
	return 1;
}

static int AddRear(Deque* que, Data value) {
	DequeNode* node = AllocDequeNode();
	if (que->front == NULL) {
		SetDequeNode(node, NULL, NULL, value);
		que->front = que->rear = node;
	} else {
		SetDequeNode(node, NULL, que->rear, value);
		que->rear->next = node;
		que->rear = node;
	}
	que->size++;
	return 1;
}

static int RemoveFront(Deque* que) {
	if (que->front == NULL) {
		return 0;
	} else if (que->front == que->rear) {
		free(que->front);
		que->front = NULL;
	} else {
		DequeNode* tmp = que->front->next;
		tmp->prev = NULL;
		free(que->front);
		que->front = tmp;
	}
	que->size--;
	return 1;
}

static int RemoveRear(Deque* que) {
	if (que->front == NULL) {
		return 0;
	} else if (que->front == que->rear) {
		free(que->front);
		que->front = NULL;
	} else {
		DequeNode* tmp = que->rear->prev;
		tmp->next = NULL;
		free(que->rear);
		que->rear = tmp;
	}
	que->size--;
	return 1;
}

static void Clear(Deque* que) {

}
