#include <stdio.h>
#include <stdlib.h>

// 연결 리스트 기초 자료형 정의
typedef struct Node {
	int data;
	struct Node* next;
} Node;

// 노드 생성 함수
Node* createNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("메모리 할당 실패 \n");
		exit(1);
	}

	newNode->data = value;
	newNode->next = NULL;

	return newNode;
}

void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("%d -> ", current -> data);
		current = current -> next;
	}
	printf("NULL\n");
}

int main() {
	Node* head = NULL;
	head = createNode(10);
	head -> next = createNode(20);
	head -> next -> next = createNode(30);

	printList(head);

	return 0;
}