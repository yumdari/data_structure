#pragma once

// �ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;



// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
//typedef struct {
//	listNode* head;
//}linkedList_h;

//linkedList_h* createLinkedList_h(void); // ����Ʈ(���) ����
//void freeLinkedList(linkedList_h* L); // ��ü ���Ḯ��Ʈ ����
void printList(); // ����Ʈ ���
//void insertFirstNode(linkedList_h* L, char* x); // ����Ʈ ù ��� ����
void insertMiddleNode(listNode* pre, char* x); // ����Ʈ �߰� ��� ����
void insertLastNode(char* x); // ����Ʈ ������ ��� ����
void deleteNode(listNode* p); // ��� ����
listNode* searchNode(char* x); // ��� Ž��
void reverse(); // ����