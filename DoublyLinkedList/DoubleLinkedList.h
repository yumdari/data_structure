#pragma once
// 이중 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	struct ListNode* llink; // 왼쪽(선행) 노드에 대한 링크
	char data[4];
	struct ListNode* rlink;
}listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* DL);
void insertNode(linkedList_h* DL, listNode* pre, char* x);
int defineKey(linkedList_h* DL, listNode* p);
void deleteNode(linkedList_h* DL, listNode* old);
listNode* searchNode(linkedList_h* DL, char* x);