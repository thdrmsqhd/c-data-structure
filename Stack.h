#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#define MAX_DATA 5

typedef struct {
	int data[MAX_DATA];
	int top;
} Stack;

void push(Stack* stack, int value);
int pop(Stack* stack);

#endif