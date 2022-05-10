#pragma once

// 단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;



// 리스트 시작을 나타내는 head 노드를 구조체로 정의
//typedef struct {
//	listNode* head;
//}linkedList_h;

//linkedList_h* createLinkedList_h(void); // 리스트(헤드) 생성
//void freeLinkedList(linkedList_h* L); // 전체 연결리스트 삭제
void printList(); // 리스트 출력
//void insertFirstNode(linkedList_h* L, char* x); // 리스트 첫 노드 삽입
void insertMiddleNode(listNode* pre, char* x); // 리스트 중간 노드 삽입
void insertLastNode(char* x); // 리스트 마지막 노드 삽입
void deleteNode(listNode* p); // 노드 삭제
listNode* searchNode(char* x); // 노드 탐색
void reverse(); // 역순