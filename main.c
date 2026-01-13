#include <stdio.h>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

int main() {
	// INT 테스트
	LinkedList* intList = createList(TYPE_INT);
	int val1 = 10;
	add(intList, &val1);
	printf("%d\n", GET_VALUE(searchNodeByIndex(intList, 0), int));
	deleteList(intList);

	// STRING 테스트
	LinkedList* strList = createList(TYPE_STRING);
	add(strList, "Hello");
	printf("%s\n", (char*)searchNodeByIndex(strList, 0)->data);

	updateNodeByIndex(strList, 0, "World");
	printf("%s\n", (char*)searchNodeByIndex(strList, 0)->data);

	deleteList(strList);

	// Stack 테스트
	Stack stack = { .top = -1 };
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	printf("Pop: %d\n", pop(&stack));
	printf("Pop: %d\n", pop(&stack));

	// Queue 테스트
	Queue queue = { .front = 0, .rear = 0, .content = 0 };
	enqueue(&queue, 100);
	enqueue(&queue, 200);
	enqueue(&queue, 300);
	printf("Dequeue: %d\n", dequeue(&queue));
	printf("Dequeue: %d\n", dequeue(&queue));

	return 0;
}