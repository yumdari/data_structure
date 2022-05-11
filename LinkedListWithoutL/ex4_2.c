#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

int main(void) {
	listNode* p;

	printf("(1) 리스트에 [월], [수], [일] 노드 삽입하기! \n");
	insertLastNode("월");
	insertLastNode("수");
	insertLastNode("일");
	printList();

	getchar();

	return 0;
}