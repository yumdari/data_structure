#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"InsertLinkedList.h"

//listNode* head = NULL;

int main()
{
	//linkedList_h* L;
	//listNode * head = NULL; // 초깃값 head is NULL
	listNode* p;

	//L = createLinkedList_h(); // 공백리스트 생성

	printf("(1) 리스트에 월, 수, 일 노드 삽입\n");
	insertLastNode("월"); insertLastNode("수"); insertLastNode("일");
	//if (head == NULL) printf("head is NULL\n");
	printList();

	printf("\n(2) 리스트에 [수] 노드 탐색하기!\n");
	p = searchNode("수");
	if (p == NULL) printf("찾는 데이터 없음");
	else printf("데이터 : %s\n", p->data);
	printList();

	printf("\n(3) 리스트의 수 뒤에 [금] 노드 삽입하기!\n");
	insertMiddleNode(p, "금");
	printList();
	
	printf("\n(4) 리스트에 [일] 노드 삭제하기!\n");
	p = searchNode("일");
	deleteNode(p);
	printList();

	printf("\n(5) 리스트 순서 역순으로 바꾸기!\n");
	reverse();
	printList();

	getchar();
	return 0;
}