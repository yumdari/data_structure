#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

int main(void) {
	listNode* p;

	printf("(1) ����Ʈ�� [��], [��], [��] ��� �����ϱ�! \n");
	insertLastNode("��");
	insertLastNode("��");
	insertLastNode("��");
	printList();

	getchar();

	return 0;
}