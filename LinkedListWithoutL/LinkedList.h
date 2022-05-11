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

void printList();
void insertLastNode(char* x);
