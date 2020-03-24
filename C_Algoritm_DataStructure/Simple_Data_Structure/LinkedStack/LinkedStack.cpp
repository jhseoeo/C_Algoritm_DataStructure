#include "./LinkedStack.h"

static int Push(LinkedStack* stack, Data value) {
	if (stack->stk == NULL) {
		stack->stk = AllocLstackNode();
		SetLstackNode(stack->stk, NULL, value);
	} else {
		LstackNode* tmp = AllocLstackNode();
		SetLstackNode(tmp, stack->stk, value);
		stack->stk = tmp;
	}
	stack->size++;
	return 1;
}

static int Pop(LinkedStack* stack, Data* value) {
	if (stack->stk == NULL) {
		return 0;
	} else {
		LstackNode* tmp = stack->stk;
		stack->stk = stack->stk->next;
		*value = tmp->data;
		free(tmp);
		stack->size--;
		return 1;
	}
}

static int Peek(const LinkedStack* stack, Data* value) {
	if (stack->stk == NULL) {
		return 0;
	} else {
		*value = stack->stk->data;
		return 1;
	}
}

static void Clear(LinkedStack* stack) {
	LstackNode* cur = stack->stk;
	LstackNode* tmp = cur;
	if (cur != NULL) {
		while (tmp != NULL) {
			tmp = cur;
			cur = cur->next;
			free(tmp);
			tmp = cur;
		}
		stack->stk = NULL;
		stack->size = 0;
	}
}

static int isEmpty(const LinkedStack* stack) {
	if (stack->stk == NULL) {
		return 1;
	} else {
		return 0;
	}
}

static int Search(const LinkedStack* stack, Data value) {
	for (LstackNode* cur = stack->stk; cur != NULL; cur = cur->next) {
		if (cur->data == value)
			return 1;
	}
	return 0;
}

static void Print(const LinkedStack* stack) {
	for (LstackNode* cur = stack->stk; cur != NULL; cur = cur->next) {
		printf("%d ", cur->data);
	}
	printf("\n");
}

static void Terminate(LinkedStack* stack) {
	Clear(stack);
}

static LinkedStack MakeLinkedStack() {
	LinkedStack tmp;
	tmp.size = 0;
	tmp.stk = NULL;
	return tmp;
}


void LinkedStack_Main() {
	LinkedStack stack = MakeLinkedStack();
	printf("Stack Created.\n");
	int input, temp;
	while (1) {
		system(CLEAR);
		Print(&stack); printf("\n");
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
			printf("Enter the number that yo want to push in the stack\n");
			printf(">>"); scanf("%d", &input);
			Push(&stack, input);
			break;
		case 2:
			Pop(&stack, &temp);
			printf("%d\n", temp);
			sleep(1500);
			break;
		case 3:
			Peek(&stack, &temp);
			printf("%d\n", temp);
			sleep(1500);
			break;
		case 4:
			printf("%s\n", isEmpty(&stack) ? "True" : "False");
			sleep(1500);
			break;
		case 5:
			Clear(&stack);
			break;
		case 6:
			printf("Enter the number that yo want to search\n");
			printf(">>"); scanf("%d", &input);
			printf("%s\n", Search(&stack, input) ? "Exist" : "Non-Exist");
			sleep(1500);
			break;
		case 0:
			Terminate(&stack);
			printf("Stack Terminated\n");
			sleep(1500);
			goto ENDLOOP;
			break;
		default: break;
		}
	} ENDLOOP:;
}
