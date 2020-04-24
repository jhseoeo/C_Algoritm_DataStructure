#include "Deque.h"

static int AddFront(Dequez* que, Data value) {
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

static int AddRear(Dequez* que, Data value) {
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

static int RemoveFront(Dequez* que, Data* value) {
	if (que->front == NULL) {
		return 0;
	} else if (que->front == que->rear) {
		*value = que->front->data;
		free(que->front);
		que->front = NULL;
	} else {
		DequeNode* tmp = que->front->next;
		tmp->prev = NULL;
		*value = que->front->data;
		free(que->front);
		que->front = tmp;
	}
	que->size--;
	return 1;
}

static int RemoveRear(Dequez* que, Data* value) {
	if (que->front == NULL) {
		return 0;
	} else if (que->front == que->rear) {
		*value = que->front->data;
		free(que->front);
		que->front = NULL;
	} else {
		DequeNode* tmp = que->rear->prev;
		tmp->next = NULL;
		*value = que->rear->data;
		free(que->rear);
		que->rear = tmp;
	}
	que->size--;
	return 1;
}

static void Clear(Dequez* que) {
	DequeNode* cur = que->front;
	DequeNode* tmp = cur;
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

static int Size(const Dequez* que) {
	return que->size;
}

static int isEmpty(const Dequez* que) {
	return que->front == NULL;
}

static int Search(const Dequez* que, Data value) {
	for (DequeNode* cur = que->front; cur != NULL; cur = cur->next) {
		if (cur->data == value)
			return 1;
	}
	return 0;
}

static void Print(const Dequez* que) {
	for (DequeNode* cur = que->front; cur != NULL; cur = cur->next) {
		printf("%d ", cur->data);
	}
	printf("\n");
}

static void Terminate(Dequez* que) {
	Clear(que);
}

static Dequez MakeDeque() {
	Dequez que;
	que.size = 0;
	que.front = que.rear = NULL;
	return que;
}

void Deque_Main() {
	Dequez deque = MakeDeque();
	printf("Deque Created.\n");
	int input, temp;
	while (1) {
		system(CLEAR);
		Print(&deque); printf("\n");
		printf("Menu\n");
		printf("1. Add front\n");
		printf("2. Add Rear\n");
		printf("3. Remove front\n");
		printf("4. Remove rear\n");
		printf("5. isEmpty\n");
		printf("6. Clear\n");
		printf("7. Search\n");
		printf("0. End\n");
		printf(">>"); scanf("%d", &input); printf("\n");

		switch (input) {
		case 1:
			printf("Enter the number that yo want to push in the queue\n");
			printf(">>"); scanf("%d", &input);
			AddFront(&deque, input);
			break;
		case 2:
			printf("Enter the number that yo want to push in the queue\n");
			printf(">>"); scanf("%d", &input);
			AddRear(&deque, input);
			break;
		case 3:
			RemoveFront(&deque, &temp);
			printf("%d\n", temp);
			sleep(1500);
			break;
		case 4:
			RemoveRear(&deque, &temp);
			printf("%d\n", temp);
			sleep(1500);
			break;
		case 5:
			printf("%s\n", isEmpty(&deque) ? "True" : "False");
			sleep(1500);
			break;
		case 6:
			Clear(&deque);
			break;
		case 7:
			printf("Enter the number that yo want to search\n");
			printf(">>"); scanf("%d", &input);
			printf("%s\n", Search(&deque, input) ? "Exist" : "Non-Exist");
			sleep(1500);
			break;
		case 0:
			Terminate(&deque);
			printf("Deque Terminated\n");
			sleep(1500);
			goto ENDLOOP;
			break;
		default: break;
		}
	} ENDLOOP:;
}