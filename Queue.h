#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

#define MAX_COMMAND 5

typedef struct {
	int commands[MAX_COMMAND];
	int front;
	int rear;
	int content;
} Queue;

void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);

#endif