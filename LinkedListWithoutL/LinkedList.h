#pragma once	//����� �ߺ� ������ ����
// �ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
// 
// �ҽ� ���Ͽ��� 
// #ifndef LinkedList.h
// #define LinkedList.h
// ���ִ� �Ͱ� ����.

typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

void printList();
void insertLastNode(char* x);
