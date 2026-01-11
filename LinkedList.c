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

// 앞에 삽입
void insertFront(Node** head, int value) {
	Node* newNode = createNode(value);
	newNode->next = *head; // 새로운 노드가 현재 가장 앞의 노드의 주소를 Next로 가르키도록 설정
	*head = newNode; // 가장 앞의 노드를 새로운 노드로 변경
}

// 특정 값을 가지는 노드를 삭제
void deleteNode(Node** head, int value) {
	Node* current = *head; // 가장 앞의 노드 부터 탐색을 시작하기 위한 노드(인덱스 의 역할을 수행).
	Node* prev = NULL;

	// -- 노드 탐색 -- 
	while (current != NULL && current->data != value) { // 현재 노드의 데이터가 매개변수 value와 다르면 노드를 다음노드로 변경
		prev = current;
		current = current->next; // 탐색을 마치면 현재 노드는 NULL이 된다.
	}

	if (current == NULL) return; // 끝까지 탐색했는데 value가 존재 하지 않을 경우

	// -- 노드 삭제 수행 --
	if (prev == NULL) { // 삭제할 노드가 head인 경우
		*head = current -> next;
	} else { // 삭제할 노드가 head가 아닌 경우 
		prev -> next = current -> next;
	}

	free(current);
}

// 특정 값을 가진 노드를 조사
Node* searchNode(Node* head, int value) {
	Node * current = head;
	while (current != NULL) {
		if (current -> data == value) return current;

		current = current -> next;
	}

	return NULL;
}

// 원하는 위치에 삽입
void insertSelect(Node** head, int value, int index) {
	Node* prev = NULL;
	Node* current = *head;
	int currIndex = 0;

	Node* newNode = createNode(value);

	if (index == 0) {
		insertFront(head, value);
		return;
	}

	// 리스트의 길이 확인
	while (current != NULL && currIndex < index) {
		prev = current;
		current = current -> next;
		currIndex = currIndex + 1;
	}

	if (prev != NULL) {
		prev -> next = newNode;
		newNode -> next = current;
	}
}

// 맨 마지막에 추가
void insertEnd(Node** head, int value) {
	Node* newNode = createNode(value);

	if (*head == NULL) {
		*head = newNode;
		return;
	}

	Node* current = *head;
	while (current->next != NULL) {
		current = current -> next;
	}

	current -> next = newNode;
}

// 리스트 사이즈 확인
int size(Node* head) {
	Node* current = head;
	int listSize = 0;

	while (current != NULL) {
		current = current -> next;
		listSize = listSize + 1;
	}

	return listSize;
}

int main() {
	Node* head = NULL;
	head = createNode(10);
	head -> next = createNode(20);
	head -> next -> next = createNode(30);

	printList(head);

	insertFront(&head, 5);
	printList(head);

	searchNode(head, 20);
	printList(head);

	deleteNode(&head, 10);
	printList(head);

	insertEnd(&head, 40);
	printList(head);

	insertSelect(&head, 2, 22);
	printList(head);

	printf("%d", size(head));

	return 0;
}