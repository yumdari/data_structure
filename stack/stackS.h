#pragma once
#define STACK_SIZE 100

typedef int element;		// 스택 원소(element)의 자료형을 int로 정의
element stack[STACK_SIZE];	// 1차원 배열 스택 선언

int isStackEmpty(void);
int isStackFull(void);
void push(element item);
element pop(void);
element peek(void);
void printStack(void);