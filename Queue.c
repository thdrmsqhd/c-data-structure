#include "Queue.h"

void enqueue(Queue* queue, int value) {
	
	if (queue->content > MAX_COMMAND - 1) {
		printf("큐가 가득 찼습니다.\n");
		return;
	}

	queue->commands[queue->rear] = value;
	queue->content = queue->content + 1;
	queue->rear = (queue->rear + 1) % MAX_COMMAND;
}

int dequeue(Queue* queue) {
	if (queue->content == -1) {
		printf("큐가 비어있습니다.\n");
		return -999;
	}

	int dequeueValue = queue->commands[queue->front];
	queue->content = queue->content - 1;
	queue->front = (queue->front + 1) % MAX_COMMAND;

	return dequeueValue;
}