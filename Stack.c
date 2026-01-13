#include "Stack.h"

void push(Stack* stack, int value) {
	if (stack->top == MAX_DATA - 1) {
		printf("Stack이 가득 찼습니다.\n");
		return;
	}

	stack->top = stack->top + 1;

	stack->data[stack->top] = value;
}

int pop(Stack* stack) {
	if (stack->top == -1) {
		printf("스택이 비어있습니다.\n");
		return -999;
	}

	int value = stack->data[stack->top];
	stack->top = stack->top - 1;

	return value;
}