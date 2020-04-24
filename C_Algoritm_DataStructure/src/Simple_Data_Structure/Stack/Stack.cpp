#include "Stack.h"

static Stack MakeStack(Data size) {
	Stack stack;
	stack.max = size;
	stack.idx = 0;
	stack.stk = (int*)malloc( stack.max * sizeof(int) );
	return stack;
}

static int Push(Stack *stack, Data value) {
	if (stack->idx < stack->max) {
		stack->stk[stack->idx++] = value;
		return 1;
	} else {
		return 0;
	}
}

static int Pop(Stack *stack, Data* value) {
	if (stack->idx > 0) {
		*value = stack->stk[--stack->idx];
		return 1;	
	} else {
		return 0;
	}
}

static int Peek(const Stack *stack, Data* value) {
	if (stack->idx > 0) {
		*value = stack->stk[stack->idx - 1];
		return 1;	
	} else {
		return 0;
	}
}

static void Clear(Stack *stack) {
	stack->idx = 0;
}

static int isEmpty(const Stack *stack) {
	return (stack->idx == 0);
}

static int isFull(const Stack *stack) {
	return (stack->idx == stack->max);	
}

static int Search(const Stack *stack, Data value) {
	for(int i = 0; i < stack->idx; i++) 
		if (stack->stk[i] == value)
			return 1;
	return 0;
}

static void Print(const Stack *stack) {
	printf("Stack's contents : ");
	for(int i = 0; i < stack->idx; i++) 
		printf("%d ", stack->stk[i]);
	printf("\n");
}

static void Terminate(Stack *stack) {
	free(stack->stk);
	stack->idx = stack->max = 0;
}

void Stack_Main() {
	Stack stack = MakeStack(10);
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
		printf("5. isFull\n");
		printf("6. Clear\n");
		printf("7. Search\n");
		printf("8. End\n");
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
			printf("%s\n", isFull(&stack) ? "True" : "False");
			sleep(1500);
			break;
		case 6:
			Clear(&stack);
			break;
		case 7:
			printf("Enter the number that yo want to search\n");
			printf(">>"); scanf("%d", &input);
			printf("%s\n", Search(&stack, input) ? "Exist" : "Non-Exist");
			sleep(1500);
			break;
		case 8:
			Terminate(&stack);
			printf("Stack Terminated\n");
			sleep(1500);
			goto ENDLOOP;
			break;
		default: break;
		}
	} ENDLOOP:;
}

Stack MakeStack_s(int size) {
	return MakeStack(size);
}

int Push_s(Stack* stack, Data value) {
	return Push_s(stack, value);
}

int Pop_s(Stack* stack, Data* value) {
	return Pop_s(stack, value);
}

int isEmpty_s(const Stack* stack) {
	return isEmpty(stack);
}

void Terminate_s(Stack* stack) {
	return Terminate(stack);
}