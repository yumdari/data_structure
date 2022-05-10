#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

int main(void) {
	linkedList_h* L;
	listNode* p;
	L = createLinkedList_h(); // 공백 리스트 생성

	printf("(1) 리스트에 [월], [수], [일] 노드 삽입하기! \n");
	insertLastNode(L, "월");
	insertLastNode(L, "수");
	insertLastNode(L, "일");
	printList(L);

	printf("\n(2) 리스트에서 [수] 노드 탐색하기! \n");
	p = searchNode(L, "수");
	if (p == NULL) {
		printf("찾는 데이터가 없습니다.\n");
	}
	else {
		printf("[%s]를 찾았습니다.\n", p->data);
	}

	printf("\n(3) 리스트의 [수] 뒤에 [금] 노드 삽입하기! \n");
	insertMiddleNode(L, p, "금");
	printList(L);

	printf("\n(4) 리스트에서 [일] 노드 삭제하기! \n");
	p = searchNode(L, "일");	// 삭제할 노드 위치 p를 찾음
	deleteNode(L, p);		// 포인터 p 노드 삭제
	printList(L);

	printf("\n(5) 리스트 순서를 역순으로 바꾸기! \n");
	reverse(L);
	printList(L);

	freeLinkedList_h(L);
	getchar();

	return 0;
}