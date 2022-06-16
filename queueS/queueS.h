#pragma once
#define Q_SIZE 4
#define char element
typedef char element;	// ť ����(element)�� �ڷ����� char�� ����

typedef struct {
	element queue[Q_SIZE];	// 1ġ�� �迭 ť ����
	int front, rear;
}QueueType;

QueueType* createQueue(void);
int isQueueEmpty(QueueType* Q);
int isQueueFull(QueueType* Q);
void enQueue(QueueType* Q, element item);
element deQueue(QueueType* Q);
element peekQ(QueueType* Q);
void printQ(QueueType*Q);