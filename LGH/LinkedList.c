#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

void freeLinkedList_h(listNode** head) {
	listNode* p;
	while (head != NULL) {
		p = (*head);
		(*head) = (*head)->link;
		free(p);
		p = NULL;
	}

}

void printList(listNode** head) {
	listNode* p;
	printf("L = (");
	p = (*head);
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(",");
	}

	printf(") \n");

}

void insertFirstNode(listNode** head, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = (*head);
	(*head) = newNode;
}

void insertMiddleNode(listNode** head, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if ((*head) == NULL) {
		newNode->link = NULL;
		(*head) = newNode;
	}
	else if (pre == NULL) {
		newNode->link = (*head);
		(*head) = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}

}

void insertLastNode(listNode** head, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if ((*head) == NULL) {
		(*head) = newNode;
		return;
	}

	temp = (*head);
	while (temp->link != NULL) temp = temp->link;
	temp->link = newNode;
}




void deleteNode(listNode** head, listNode* p)
{
	listNode* pre;
	if ((*head) == NULL) return;
	if ((*head)->link == NULL) {
		free(head);
		head = NULL;
		return;
	}
	else if (p == NULL) return;
	else {
		pre = (*head);
		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link;
		free(p);
	}

}

listNode* searchNode(listNode** head, char* x){
	listNode* temp;
	temp = (*head);
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	}

	return temp;
}

void reverse(listNode** head) {
	listNode* p;
	listNode* q;
	listNode* r;

	p = (*head);
	q = NULL;
	r = NULL;

	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}

	(*head) = q;
}