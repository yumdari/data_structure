#include <stdio.h>
#include "stackL.h"

int main(void) {
	element item;
	top = NULL;
	printf("\b**연결 스택 연산 **\n");
	printStack();

	push(1); printStack();
	push(2); printStack();
	push(3); printStack();

	item = peek(); printStack();
	printf("peek => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	getchar(); return 0;
}