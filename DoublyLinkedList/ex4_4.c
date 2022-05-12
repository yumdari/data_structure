#include<stdlib.h>
#include"DoubleLinkedList.h"

int main(void) {
	linkedList_h* DL;
	listNode* p;

	DL = createLinkedList_h();
	printf("(1) 이중 연결 리스트 생성하기! \n");
	printList(DL);

	printf("\n(2) 이중 연결 리스트에 [월] 노드 삽입하기! \n");
	insertNode(DL, NULL, "월");
	printList(DL);

	printf("\n(3) 이중 연결 리스트의 [월] 노드 뒤에 [수] 노드 삽입하기! \n");
	p = searchNode(DL, "월"); insertNode(DL, p, "수");
	printList(DL);

	printf("\n(4) 이중 연결 리스트의 [수] 노드 뒤에 [금] 노드 삽입하기! \n");
	p = searchNode(DL, "수");
	insertNode(DL, p, "금");
	printList(DL);

	printf("\n(5) 이중 연결 리스트에서 [수] 노드 삭제하기! \n");
	p = searchNode(DL, "금");
	deleteNode(DL, p);
	printList(DL);

	getchar();
	return 0;
}