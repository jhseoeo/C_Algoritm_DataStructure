#include "Queue.h"

static int Enque(Queue *que, int value) {
	if((que->rear + 1) % que->max != que->front) {
		que->queue[que->rear] = value;
		que->rear = (que->rear + 1) % que->max;
		return 1;
	} else {
		return 0;
	}
}

static int Deque(Queue *que, int* value) {
	if(que->front != que->rear) {
		*value = que->queue[que->front];
		que->front = (que->front + 1) % que->max;
		return 1;
	} else {
		return 0;
	}
}

static int Peek(const Queue *que, int* value) {
	if(que->front != que->rear) {
		*value = que->queue[que->front];
		return 1;
	} else {
		return 0;
	}
}

static void Clear(Queue *que) {
	que->front = que->rear = 0;	
}

static int Size(const Queue *que) {
	return (que->rear - que->front) >= 0 ? (que->rear - que->front) : (que->max - que->front + que->rear);
}

static int isEmpty(const Queue *que) {
	return que->front == que->rear;
}

static int isFull(const Queue *que) {
	return (que->rear + 1) % que->max == que->front;
}

static int Search(const Queue *que, int value) {
	for(int i = que->front; i % que->max != que->rear; i = (i + 1) % que->max) {
		if(que->queue[i] == value)
			return 1;	
	}
	return 0;
}

static void Print(const Queue *que) {
	printf("Queue's contents : ");
	for(int i = que->front; i != que->rear; i = (i + 1) % que->max) {
		printf("%d ", que->queue[i]);
	}
	printf("\n");
}

static void Terminate(Queue *que) {
	free(que->queue);
	que->front = que->rear = 0;
}

static Queue MakeQueue(int size) {
	Queue que;
	que.max = size + 1;
	que.front = que.rear = 0;
	que.queue = (int*)malloc( que.max * sizeof(int) );
	return que;
}

void Queue_Main() {
	Queue queue = MakeQueue(5);
	printf("Queue Created.\n");
	int input, temp;
	while (1) {
		system("cls");
		Print(&queue); printf("\n");
		printf("Menu\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. isEmpty\n");
		printf("5. isFull\n");
		printf("6. Clear\n");
		printf("7. Search\n");
		printf("8. End\n");
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
			Sleep(1500);
			break;
		case 3:
			Peek(&queue, &temp);
			printf("%d\n", temp);
			Sleep(1500);
			break;
		case 4:
			printf("%s\n", isEmpty(&queue) ? "True" : "False");
			Sleep(1500);
			break;
		case 5:
			printf("%s\n", isFull(&queue) ? "True" : "False");
			Sleep(1500);
			break;
		case 6:
			Clear(&queue);
			break;
		case 7:
			printf("Enter the number that yo want to search\n");
			printf(">>"); scanf("%d", &input);
			printf("%s\n", Search(&queue, input) ? "Exist" : "Non-Exist");
			Sleep(1500);
			break;
		case 8:
			Terminate(&queue);
			printf("Queue Terminated\n");
			Sleep(1500);
			goto ENDLOOP;
			break;
		default: break;
		}
	} ENDLOOP:;
}
