#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"InsertLinkedList.h"

//listNode* head = NULL;

int main()
{
	//linkedList_h* L;
	//listNode * head = NULL; // �ʱ갪 head is NULL
	listNode* p;

	//L = createLinkedList_h(); // ���鸮��Ʈ ����

	printf("(1) ����Ʈ�� ��, ��, �� ��� ����\n");
	insertLastNode("��"); insertLastNode("��"); insertLastNode("��");
	//if (head == NULL) printf("head is NULL\n");
	printList();

	printf("\n(2) ����Ʈ�� [��] ��� Ž���ϱ�!\n");
	p = searchNode("��");
	if (p == NULL) printf("ã�� ������ ����");
	else printf("������ : %s\n", p->data);
	printList();

	printf("\n(3) ����Ʈ�� �� �ڿ� [��] ��� �����ϱ�!\n");
	insertMiddleNode(p, "��");
	printList();
	
	printf("\n(4) ����Ʈ�� [��] ��� �����ϱ�!\n");
	p = searchNode("��");
	deleteNode(p);
	printList();

	printf("\n(5) ����Ʈ ���� �������� �ٲٱ�!\n");
	reverse();
	printList();

	getchar();
	return 0;
}