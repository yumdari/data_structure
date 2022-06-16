#include "LinkedQueue.h"

int main(void) {
	LQueueType* LQ = createLinkedQueue();
	element data;
	printf("\n ***** 연결 큐 연산 ***** \n");
	printf("\n 삽입 A>>"); enLQueue(LQ, 'A'); printLQ(LQ);
	printf("\n 삽입 B>>"); enLQueue(LQ, 'B'); printLQ(LQ);
	printf("\n 삽입 C>>"); enLQueue(LQ, 'C'); printLQ(LQ);
	data = peekLQ(LQ); printf(" peek item : %c \n", data);
	printf("\n 삭제 >>"); data = deLQueue(LQ); printLQ(LQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>"); data = deLQueue(LQ); printLQ(LQ);
	printf("\t\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>"); data = deLQueue(LQ); printLQ(LQ);
	printf("\t\t 삭제 데이터 : %c", data);

	printf("\n 삽입 D>> "); enLQueue(LQ, 'D'); printLQ(LQ);
	printf("\n 삽입 E>>"); enLQueue(LQ, 'E'); printLQ(LQ);
	getchar(); return 0;
}