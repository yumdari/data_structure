#include <stdio.h>
#include "LinkedList.h"



int main(void) {
	listNode* head1;
	listNode* p; // ã�� ���
	head1 = NULL;

	printf("(1) ����Ʈ�� [��], [��], [��] ��� �����ϱ�! \n");
	insertLastNode(&head1, "��"); 
	insertLastNode(&head1, "��");
	insertLastNode(&head1, "��");
	printList(&head1);

	printf("\n(2) ����Ʈ�� [��] ��� Ž���ϱ�! \n");
	p = searchNode(&head1, "��");
	if (p == NULL) printf("ã�� �����Ͱ� �����ϴ�.\n");
	else printf("[%s]�� ã�ҽ��ϴ�.\n", p->data);

	printf("\n(3) ����Ʈ�� [��] �ڿ� [��] ��� �����ϱ�! \n");
	insertMiddleNode(&head1, p , "��");
	printList(&head1);

	printf("\n(4) ����Ʈ���� [��] ��� �����ϱ�! \n");
	p = searchNode(&head1, "��");
	deleteNode(&head1, p);
	printList(&head1);

	printf("\n(5) ����Ʈ ������ �������� �ٲٱ�! \n");
	reverse(&head1);
	printList(&head1);

	freeLinkedList_h(&head1);

	getchar();

	return 0;
}