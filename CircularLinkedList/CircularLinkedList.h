#pragma once
// 원형 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* CL);
void insertFirstNode(linkedList_h* CL, char* x);
void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x);
void deleteNode(linkedList_h* CL, listNode* old);
listNode* serachNode(linkedList_h* CL, char* x);