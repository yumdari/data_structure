#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"InsertLinkedList.h"

//listNode* head;
listNode* head = NULL;

// 공백 연결 리스트를 생성하는 연산
//linkedList_h* createLinkedList_h(void) {
//	linkedList_h* L;
//	L = (linkedList_h*)malloc(sizeof(linkedList_h));
//	if (L == NULL) {
//		printf("fail malloc\n");
//		return NULL;
//	}
//	L->head = NULL;
//	return L;
//}

// 연결 리스트의 전체 메모리를 해제하는 연산
//void freeLinkedList(linkedList_h* L) {
//	listNode* p;
//	while (L->head != NULL) {
//		p = L->head;
//		L->head = L->head->link;
//		free(p);
//		p = NULL;
//	}
//
//}

// 연결 리스트를 순서대로 출력하는 연산
void printList() {
	listNode* p;
	printf("L=(");
	p = head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL)printf(", ");
	}
	printf(") \n");
}

// 첫 번째 노드로 삽입하는 연산
//void insertFirstNode(linkedList_h* L, char* x) {
//	listNode* newNode;
//	newNode = (listNode*)malloc(sizeof(listNode));
//	if (newNode == NULL) {
//		printf("fail malloc\n");
//		return;
//	}
//	strcpy(newNode->data, x);
//	newNode->link = L->head;
//	L->head = newNode;
//}

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	if (newNode == NULL) {
		printf("fail malloc\n");
		return;
	}
	strcpy(newNode->data, x);

	if (head == NULL) {
		newNode->link = NULL;
		head = newNode;
	}
	else if (pre == NULL) {
		newNode->link = head;
		head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

// 마지막 노드로 삽입
void insertLastNode(char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	if (newNode == NULL) {
		printf("fail malloc\n");
		return;
	}
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (head == NULL) {
		head = newNode;
		return;
	}

	temp = head;
	while (temp->link != NULL) {
		temp = temp->link;
	}
	temp->link = newNode;
}

void deleteNode(listNode* p) {
	listNode* pre;
	// 공백 리스트일 경우
	if (head == NULL) {
		return;
	}
	// 노드가 한개만 있을 경우
	if (head->link == NULL) {
		free(head);
		head = NULL;
	}
	// 삭제할 노드가 없다면..
	else if (p == NULL) return;

	//이전 노드 탐색
	else {
		pre = head;
		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link; // 이전노드의 링크필드에 삭제할 노드의 링크필드 값 대입
		free(p);
	}
}
listNode* searchNode(char* x) {
	listNode* ptr;
	if (head == NULL) return NULL;
	else {
		ptr = head;
		while (ptr != NULL) {
			if (strcmp(ptr->data, x) == 0)
				return ptr;
			ptr = ptr->link;
		}
	}
	return ptr;
}
void reverse() {
	listNode* p;
	listNode* q;
	listNode* r;

	p = head;
	q = NULL;
	r = NULL;

	while (p != NULL) {
		/* r -> q -> p */
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	head = q;
}