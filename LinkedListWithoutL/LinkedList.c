#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkedList.h"

listNode* head = NULL;

// ���� ����Ʈ�� ������� ����ϴ� ����
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


// ������ ���� �����ϴ� ����
void insertLastNode(char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (head == NULL) {	// ���� ����Ʈ�� ������ ���
		head = newNode;	// �� ��带 ����Ʈ�� ���� ���� ����
		return;
	}
	// ���� ����Ʈ�� ������ �ƴ� ���
	temp = head;
	while (temp->link != NULL) {	// ���� ����Ʈ�� ������ ��带 ã��
		temp = temp->link;			// �� ��带 ������ ���(temp)�� ���� ���� ����
	}
	temp->link = newNode;
}
