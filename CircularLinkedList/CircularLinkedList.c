#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include"CircularLinkedList.h"

// 공백 원형 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
	linkedList_h* CL;
	CL = (linkedList_h*)malloc(sizeof(linkedList_h));
	CL->head = NULL;
	return CL;
}

// 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* CL) {
	listNode* p;
	printf(" CL = (");
	p = CL->head;
	if (p == NULL) {
		printf(")\n"); return;
	}
	do {
		printf("%s", p->data);
		p = p->link;
		if (p != CL->head) {
			printf(", ");
		}
	} while (p != CL->head);
	printf(") \n");
}

//첫 번째 노드 삽입 연산
void insertFirstNode(linkedList_h* CL, char* x) {
	listNode* newNode, * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL->head == NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {
		temp = CL->head;
		while (temp->link != CL->head) {
			temp = temp->link;
		}
		newNode->link = temp->link;
		temp->link = newNode;
		CL->head = newNode;
	}
}

// pre 뒤에 노드를 삽입하는 연산
void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL->head == NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

// 원형 연결 리스트의 pre 뒤에 있는 노드 old를 삭제하는 연산
void deleteNode(linkedList_h* CL, listNode* old) {
	listNode* pre;
	if (CL->head == NULL) {
		return;
	}
	if (CL->head->link == CL->head) {
		free(CL->head);
		CL->head = NULL;
		return;
	}
	else if (old == NULL) {
		return;
	}
	else {
		pre = CL->head;
		while (pre->link != old) {
			pre = pre->link;
		}
		pre->link = old->link;
		if (old == CL->head) {
			CL->head = old->link;
		}
		free(old);
	}
}

// 원형 연결 리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(linkedList_h* CL, char* x) {
	listNode* temp;
	temp = CL->head;
	if (temp == NULL) {
		return;
	}
	do {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	} while (temp != CL->head);
	return NULL;
}