#include "LinkedQueue.h"

static int Enque(LinkedQueue* que, Data value) {
	LqueueNode* node = AllocLqueueNode();

	if (que->front == NULL) {
		SetLqueueNode(node, NULL, value);
		que->front = que->rear = node;
	} else {
		SetLqueueNode(node, que->front, value);
		que->front = node;
	}
	que->size++;
	return 1;
}

static int Deque(LinkedQueue* que, Data* value) {
	// 원래대로라면 Circular linked list를 이용하여 구현해야 하지만 귀찮아서 반복문돌림
	if (que->front == NULL) {
		return 0;
	} else if (que->front == que->rear) {
		*value = que->front->data;
		free(que->front);
		que->front = que->rear = NULL;
	} else {
		LqueueNode* cur;
		for (cur = que->front; cur->next != que->rear; cur = cur->next);
		*value = cur->next->data;
		cur->next = NULL;
		free(que->rear);
		que->rear = cur;
	}
	que->size--;
	return 1;
}

static int Peek(const LinkedQueue* que, Data* value) {
	if (que->front == NULL) {
		return 0;
	} else {
		*value = que->rear->data;
		return 1;
	}
}

static void Clear(LinkedQueue* que) {
	LqueueNode* cur = que->front;
	LqueueNode* tmp = cur;
	if (cur != NULL) {
		while (tmp != NULL) {
			tmp = cur;
			cur = cur->next;
			free(tmp);
			tmp = cur;
		}
		que->front = que->rear = NULL;
		que->size = 0;
	}
}

static int Size(const LinkedQueue* que) {
	return que->size;
}

static int isEmpty(const LinkedQueue* que) {
	return que->front == NULL;
}

static int Search(const LinkedQueue* que, Data value) {
	for (LqueueNode* cur = que->front; cur != NULL; cur = cur->next) {
		if (cur->data == value)
			return 1;
	}
	return 0;
}

static void Print(const LinkedQueue* que) {
	for (LqueueNode* cur = que->front; cur != NULL; cur = cur->next) {
		printf("%d ", cur->data);
	}
	printf("\n");
}

static void Terminate(LinkedQueue* que) {
	Clear(que);
}

static LinkedQueue MakeLinkedQueue() {
	LinkedQueue que;
	que.front = que.rear = NULL;
	que.size = 0;
	return que;
}

void LinkedQueue_Main() {
	LinkedQueue queue = MakeLinkedQueue();
	printf("Queue Created.\n");
	int input, temp;
	while (1) {
		system(CLEAR);
		Print(&queue); printf("\n");
		printf("Menu\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. isEmpty\n");
		printf("5. Clear\n");
		printf("6. Search\n");
		printf("0. End\n");
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
			Clear(&queue);
			break;
		case 6:
			printf("Enter the number that yo want to search\n");
			printf(">>"); scanf("%d", &input);
			printf("%s\n", Search(&queue, input) ? "Exist" : "Non-Exist");
			sleep(1500);
			break;
		case 0:
			Terminate(&queue);
			printf("Queue Terminated\n");
			sleep(1500);
			goto ENDLOOP;
			break;
		default: break;
		}
	} ENDLOOP:;
}