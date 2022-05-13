#pragma once
#define STACK_SIZE 100

typedef int element;		// ���� ����(element)�� �ڷ����� int�� ����
element stack[STACK_SIZE];	// 1���� �迭 ���� ����

int isStackEmpty(void);
int isStackFull(void);
void push(element item);
element pop(void);
element peek(void);
void printStack(void);