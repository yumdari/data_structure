#include<stdio.h>
#include<stdlib.h>
#include"queueS.h"

// 공백 순차 큐를 생성하는 연산
QueueType* createQueue(void) {
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;	// front 초깃값 설정
	Q->rear = -1;	// rear 초깃값 설정
	return Q;
}

// 순차 큐가 공백 상태인지 검사하는 연산
int isQueueEmpty(QueueType* Q) {
	if (Q->front == Q->rear) {
		printf(" Queue is empty! \n\t ");
		return 1;
	}
	else return 0;
}

// 순차 큐가 포화 상태인지 검사하는 연산
int isQueueFull(QueueType* Q) {
	if (Q->rear == Q_SIZE - 1) {
		printf(" Queue is full! \n\t ");
		return 1;
	}
	else return 0;
}

// 순차 큐의 rear에 원소를 삽입하는 연산
void enQueue(QueueType* Q, element item) {
	if (isQueueFull(Q)) return;	// 포화 상태이면, 삽입 연산 중단
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}

// 순차 큐의 front에서 원소를 삭제하는 연산
element deQueue(QueueType* Q) {
	if (isQueueEmpty(Q)) return;	// 공백 상태이면, 삭제 연산 중단
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}

// 순차 큐의 가장 앞에 있는 원소를 검색하는 연산
element peekQ(QueueType* Q) {
	if (isQueueEmpty(Q)) return;	// 공백 상태이면 연산 중단
	else return Q->queue[Q->front + 1];
}

// 순차 큐의 원소를 출력하는 연산
void printQ(QueueType* Q) {
	printf(" Queue : [");
	for (int idx = Q->front + 1; idx <= Q->rear; idx++) {
		printf("%3c", Q->queue[idx]);
	}
	printf(" ]");
}