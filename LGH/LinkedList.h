#pragma once

typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} listNode;



void freeLinkedList_h(listNode** head);
void printList(listNode** head);

void insertFirstNode(listNode** head, char* x);
void insertMiddleNode(listNode** head,listNode* pre, char* x);
void insertLastNode(listNode** head, char* x);

void deleteNode(listNode** head, listNode* p);
listNode* searchNode(listNode** head, char* x);
void reverse(listNode** head);