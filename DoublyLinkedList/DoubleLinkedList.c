#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include"DoubleLinkedList.h"
int key = 0;

//공백 이중 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
	linkedList_h* DL;
	DL = (linkedList_h*)malloc(sizeof(linkedList_h));
	DL->head = NULL;
	return DL;
}

// 이중 연결 리스트를 순서대로 출력하는 연산
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

// pre 뒤에 노드를 삽입하는 연산
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
	if ((DL->head == NULL) || (old == NULL)) {// 공백리스트일 때, 못찾았을 때
		key = 0;
	}
	else if (old->llink == NULL) {	// 첫 노드일 때
		key = 1;
	}
	else if (old->rlink == NULL) {	// 마지막 노드일 때
		key = 2;
	}
	else {	// 중간 노드일 때
		key = 3;
	}
	return key;
}
// 이중 연결 리스트에서 old 노드를 삭제하는 연산
void deleteNode(linkedList_h* DL, listNode* old) {
	key = defineKey(DL, old);
	switch (key) {
	case 1:	// 첫 노드일 때
		DL->head = old->rlink;
		old->rlink->llink = NULL;
		break;
	case 2:	// 마지막 노드일 때
		old->llink->rlink = NULL;
		break;
	case 3:	// 중간 노드일 때	
		old->llink->rlink = old->rlink;
		old->rlink->llink = old->llink;
		break;
	}
	free(old);
	return;
}

// 리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(linkedList_h* DL, char* x) {
	listNode* temp;
	temp = DL->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->rlink;
		}
	return temp;
}
