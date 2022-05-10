#pragma once	//헤더의 중복 선언을 방지
// 단순 연결 리스트의 노드 구조를 구조체로 정의
// 
// 소스 파일에서 
// #ifndef LinkedList.h
// #define LinkedList.h
// 해주는 것과 같다.

typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

// 리스트의 시작을 나타내는 head 정의
typedef struct {
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h(void);
void freeLinkedList_h(linkedList_h* L);
void printList(linkedList_h* L);
void insertFirstNode(linkedList_h* L, char* x);
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x);
void insertLastNode(linkedList_h* L, char* x);
void deleteNode(linkedList_h* L, listNode* p);
listNode* searchNode(linkedList_h* L, char* x);
void reverse(linkedList_h* L);