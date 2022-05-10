#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkedList.h"

// 공백 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;	// 공백 리스트이므로 NULL로 설정
	return L;
}

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* L) {
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

// 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* L) {
	listNode* p;
	printf("L=(");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) {
			printf(",");
		}
	}
	printf(") \n");
}
// 첫 번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h* L, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));	// 삽입할 새 노드 할당
	strcpy(newNode->data, x);						// 새 노드의 데이터 필드에 x 저장
	newNode->link = L->head;
	L->head = newNode;
}

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (L->head == NULL) {		// 공백 리스트인 경우
		newNode->link = NULL;	// 새 노드를 첫 번째이자 마지막 노드로 연결
		L->head = newNode;
	}
	else if (pre == NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

// 마지막 노드로 삽입하는 연산
void insertLastNode(linkedList_h* L, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {	// 현재 리스트가 공백인 경우
		L->head = newNode;	// 새 노드를 리스트의 시작 노드로 연결
		return;
	}
	// 현재 리스트가 공백이 아닌 경우
	temp = L->head;
	while (temp->link != NULL) {	// 현재 리스트의 마지막 노드를 찾음
		temp = temp->link;			// 새 노드를 마지막 노드(temp)의 다음 노드로 연결
	}
	temp->link = newNode;
}

// 리스트에서 노드 p를 삭제하는 연산
void deleteNode(linkedList_h* L, listNode* p) {
	listNode* pre;					// 삭제할 노드의 선행자 노드를 나타낼 포인터
	if (L->head == NULL) {			// 공백 리스트라면 삭제 연산 중단
		return;
	}
	if (L->head->link == NULL) {	// 리스트에 노드가 한 개만 있는 경우
		free(L->head);				// 첫 번째 노드를 메모리에서 해제하고
		L->head = NULL;				// 리스트 시작 포인터를 NULL로 설정
		return;
	}
	else if (p == NULL) return;		// 삭제할 노드가 없다면 삭제 연산 중단
	else {							// 삭제할 노드 p의 선행자 노드를 포인터 pre를 이용해 찾음
		pre = L->head;
		while (pre->link != p) {	// 이 함수의 포인트
			pre = pre->link;
		}
		pre->link = p->link;		// 삭제할 노드 p의 선행자 노드와 다음 노드를 연결
		free(p);					// 삭제 노드의 메모리 해제
	}
}

// 리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(linkedList_h* L, char* x) {
	listNode* temp;
	temp = L->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) {
			return temp;
		}
		else temp = temp->link;
	}
	return temp;
}
// 리스트의 노드 순서를 역순으로 바꾸는 연산
void reverse(linkedList_h* L) {
	listNode* p;
	listNode* q;
	listNode* r;

	p = L->head;	// 포인터 p를 첫 번째 노드에 설정
	q = NULL;
	r = NULL;

	// 리스트의 첫 번째 노드부터 링크를 따라 다음 노드로 이동하면서
	// 노드 간의 연결을 바꿈

	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	L->head = q;
}