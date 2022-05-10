#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"InsertLinkedList.h"

//listNode* head;
listNode* head = NULL;

// ���� ���� ����Ʈ�� �����ϴ� ����
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

// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
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

// ���� ����Ʈ�� ������� ����ϴ� ����
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

// ù ��° ���� �����ϴ� ����
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

// ��带 pre �ڿ� �����ϴ� ����
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

// ������ ���� ����
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
	// ���� ����Ʈ�� ���
	if (head == NULL) {
		return;
	}
	// ��尡 �Ѱ��� ���� ���
	if (head->link == NULL) {
		free(head);
		head = NULL;
	}
	// ������ ��尡 ���ٸ�..
	else if (p == NULL) return;

	//���� ��� Ž��
	else {
		pre = head;
		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link; // ��������� ��ũ�ʵ忡 ������ ����� ��ũ�ʵ� �� ����
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