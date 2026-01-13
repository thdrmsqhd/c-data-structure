#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

LinkedList* createList(DataType type) {
	LinkedList* list = (LinkedList*) malloc(sizeof (LinkedList));

	if (list == NULL) {
		printf("노드를 추가하기 위한 메모리를 할당 받지 못했습니다.\n");
		return NULL;
	}

	list->head = NULL;
	list->type = type;

	return list;
}

// 리스트 사이즈 확인
int size(LinkedList* list) {
	if(list == NULL) return 0;
	Node* currentNode = list->head;
	if (currentNode == NULL) return 0;

	int listSize = 0;

	while (currentNode != NULL) {
		currentNode = currentNode->next;
		listSize = listSize + 1;
	}

	return listSize;
}

// 노드 추가 함수
void add(LinkedList* list, void* value) {
	int listSize = size(list);

	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("노드를 추가하기 위한 메모리를 할당 받지 못했습니다.\n");
		return;
	}

	switch (list->type) {
		case TYPE_INT:
			newNode->data = malloc(sizeof(int));
			if (newNode->data == NULL) {
				free(newNode);
				return;
			}
			*(int*)newNode->data = *(int*) value;
			break;
		case TYPE_FLOAT:
			newNode->data = malloc(sizeof(float));
			if (newNode->data == NULL) {
				free(newNode);
				return;
			}
			*(float*)newNode->data = *(float*) value;
			break;
		case TYPE_STRING:
			newNode->data = malloc(strlen((char*)value) + 1);
			if (newNode->data == NULL) {
				free(newNode);
				return;
			}
			strcpy_s((char*)newNode->data, strlen((char*)value) + 1, (char*)value);
			break;
	}

	if (listSize == 0) {
		newNode->prev = NULL;
		newNode->next = NULL;
		list->head = newNode;
	} else {
		Node* prevNode = searchNodeByIndex(list, listSize - 1);
		prevNode->next = newNode;
		newNode->prev = prevNode;
		newNode->next = NULL;
	}
}

// 인덱스 기반으로 노드 검색
Node* searchNodeByIndex(LinkedList* list, int index) {
	Node* currentNode = list->head;
	int currentIndex = 0;
	while (currentNode != NULL && currentIndex < index) {
		currentNode = currentNode->next;
		currentIndex = currentIndex + 1;
	}

	return currentNode;
}

void updateNodeByIndex(LinkedList* list, int index, void* value) {
	Node* searchedNode = searchNodeByIndex(list, index);
	if (searchedNode == NULL) {
		printf("해당 인덱스에 해당하는 데이터가 존재 하지 않습니다.\n");
		return;
	}
	switch (list->type) {
	case TYPE_INT:
		*(int*)searchedNode->data = *(int*)value;
		break;
	case TYPE_FLOAT:
		*(float*)searchedNode->data = *(float*)value;
		break;
	case TYPE_STRING:
		free(searchedNode->data);
		searchedNode->data = malloc(strlen((char*)value) + 1);
		if (searchedNode->data == NULL) {
			printf("메모리 할당 실패\n");
			return;
		}
		strcpy_s((char*)searchedNode->data, strlen((char*)value) + 1, (char*)value);
		break;
	}
}

void deleteNodeByIndex(LinkedList* list, int index) {
	Node* searchedNode = searchNodeByIndex(list, index);
	if (searchedNode == NULL) {
		printf("해당 인덱스에 해당하는 데이터가 존재 하지 않습니다.\n");
		return;
	}

	if (searchedNode->prev == NULL){
		list->head = searchedNode->next;
	} else {
		searchedNode->prev->next = searchedNode->next;
	}

	if (searchedNode->next != NULL) {
		searchedNode->next->prev = searchedNode->prev;
	}

	free(searchedNode->data);
	free(searchedNode);
}

void deleteList(LinkedList* list) {
	Node* currentNode = list->head;
	while (currentNode != NULL) {
		Node* nextNode = currentNode->next;
		free(currentNode->data);
		free(currentNode);

		currentNode = nextNode;
	}
	free(list);
}