#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define GET_VALUE(node, TYPE)	(*(TYPE*)((node)->data))

typedef enum DataType {
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_STRING
} DataType;

typedef struct Node {
	void* data;
	struct Node* next;
	struct Node* prev;
} Node;

typedef struct LinkedList {
	struct Node* head;
	enum DataType type;
} LinkedList;

// 함수 선언
LinkedList* createList(DataType type);
Node* searchNodeByIndex(LinkedList* list, int index);
int size(LinkedList* list);
void add(LinkedList* list, void* value);
void updateNodeByIndex(LinkedList* list, int index, void* value);
void deleteNodeByIndex(LinkedList* list, int index);
void deleteList(LinkedList* list);

#endif
