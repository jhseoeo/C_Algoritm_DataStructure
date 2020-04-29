#include "Priority_Queue.h"

static int Enque(PriorityQueue* que, Data value) {
	if (Heap_Insert(&(que->heap), value))
		return 1;
	else
		return 0;
}

static int Deque(PriorityQueue* que, Data* value) {
	*value = Heap_Delete(&(que->heap));
	if (*value != -1)
		return 1;
	else
		return 0;
}

static int Peek(const PriorityQueue* que, Data* value) {
	if (que->heap.size == 0) {
		return 0;
	} else {
		*value = que->heap.arr[1];
		return 1;
	}
}

static void Clear(PriorityQueue* que) {
	que->heap.size = 0;
}

static int Size(const PriorityQueue* que) {
	return que->heap.size;
}

static int isEmpty(const PriorityQueue* que) {
	return que->heap.size == 0;
}

static int isFull(const PriorityQueue* que) {
	return que->heap.size == que->heap.max;
}

static void Print(const PriorityQueue* que) {
	for (int i = 1; i <= que->heap.size; i++) {
		printf("%d ", que->heap.arr[i]);
	}
}

static void Terminate(PriorityQueue* que) {
	free(que->heap.arr);
}

static PriorityQueue MakePriorityQueue(int size) {
	PriorityQueue queue;
	queue.heap = MakeNewHeap(size);
	return queue;
}

void PriorityQueue_Main() {
	PriorityQueue queue = MakePriorityQueue(10);
	printf("PriorityQueue Created.\n");
	int input, temp;
	while (1) {
		system(CLEAR);
		Print(&queue); printf("\n");
		printf("Menu\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. isEmpty\n");
		printf("5. isFull\n");
		printf("6. Clear\n");
		printf("7. End\n");
		printf(">>"); scanf("%d", &input); printf("\n");

		switch (input) {
		case 1:
			printf("Enter the number that yo want to push in the queue\n");
			printf(">>"); scanf("%d", &input);
			Enque(&queue, input);
			break;
		case 2:
			Deque(&queue, &temp);
			printf("%d\n", temp);
			sleep(1500);
			break;
		case 3:
			Peek(&queue, &temp);
			printf("%d\n", temp);
			sleep(1500);
			break;
		case 4:
			printf("%s\n", isEmpty(&queue) ? "True" : "False");
			sleep(1500);
			break;
		case 5:
			printf("%s\n", isFull(&queue) ? "True" : "False");
			sleep(1500);
			break;
		case 6:
			Clear(&queue);
			break;
		case 7:
			Terminate(&queue);
			printf("Queue Terminated\n");
			sleep(1500);
			goto ENDLOOP;
			break;
		default: break;
		}
	} ENDLOOP:;
}