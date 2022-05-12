#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include"DoubleLinkedList.h"
int key = 0;

//���� ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void) {
	linkedList_h* DL;
	DL = (linkedList_h*)malloc(sizeof(linkedList_h));
	DL->head = NULL;
	return DL;
}

// ���� ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* DL) {
	listNode* p;
	printf("DL = (");

	p = DL->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL)printf(",");
	}
	printf(") \n");
}

// pre �ڿ� ��带 �����ϴ� ����
void insertNode(linkedList_h* DL, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (DL->head == NULL) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		DL->head = newNode;
	}
	else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL) {
			newNode->rlink->llink = newNode;
		}
	}
}
int defineKey(linkedList_h* DL, listNode* old){
	if ((DL->head == NULL) || (old == NULL)) {// ���鸮��Ʈ�� ��, ��ã���� ��
		key = 0;
	}
	else if (old->llink == NULL) {	// ù ����� ��
		key = 1;
	}
	else if (old->rlink == NULL) {	// ������ ����� ��
		key = 2;
	}
	else {	// �߰� ����� ��
		key = 3;
	}
	return key;
}
// ���� ���� ����Ʈ���� old ��带 �����ϴ� ����
void deleteNode(linkedList_h* DL, listNode* old) {
	key = defineKey(DL, old);
	switch (key) {
	case 1:	// ù ����� ��
		DL->head = old->rlink;
		old->rlink->llink = NULL;
		break;
	case 2:	// ������ ����� ��
		old->llink->rlink = NULL;
		break;
	case 3:	// �߰� ����� ��	
		old->llink->rlink = old->rlink;
		old->rlink->llink = old->llink;
		break;
	}
	free(old);
	return;
}

// ����Ʈ���� x ��带 Ž���ϴ� ����
listNode* searchNode(linkedList_h* DL, char* x) {
	listNode* temp;
	temp = DL->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->rlink;
		}
	return temp;
}
