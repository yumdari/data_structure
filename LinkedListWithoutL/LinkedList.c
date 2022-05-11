#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkedList.h"

listNode* head = NULL;

// 연결 리스트를 순서대로 출력하는 연산
void printList() {
	listNode* p;
	printf("L=(");
	p = head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) {
			printf(",");
		}
	}
	printf(") \n");
}


// 마지막 노드로 삽입하는 연산
void insertLastNode(char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (head == NULL) {	// 현재 리스트가 공백인 경우
		head = newNode;	// 새 노드를 리스트의 시작 노드로 연결
		return;
	}
	// 현재 리스트가 공백이 아닌 경우
	temp = head;
	while (temp->link != NULL) {	// 현재 리스트의 마지막 노드를 찾음
		temp = temp->link;			// 새 노드를 마지막 노드(temp)의 다음 노드로 연결
	}
	temp->link = newNode;
}
