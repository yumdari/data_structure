//단순 연결리스트는 하나의 링크 필드를 이용하여 연결하며 마지막 노드의 링크 값은 NULL을 가리켜야 합니다.
//단순 연결리스트 Abstract Data Type
//insert_first()
//리스트의 시작 부분에 항목을 삽입하는 함수
//insert()
//리스트의 중간 부분에 항목을 삽입하는 함수
//delete_first()
//리스트의 첫 번째 항목을 삭제하는 함수
//delete()
//리스트의 중간 항목을 삭제하는 함수(도전 문제)
//print_list()
//리스트를 방문하여 모든 항목을 출력하는 함수

//This iz a basic algorithm for simple linked-list
 # include < stdio.h >
 # include < stdlin.h >
 # include < malloc.h >

typedef int element;
// 노드 타입을 구조체로 정의
typedef struct ListNode {
    element data;
    struct ListNode * link;
}
ListNode;
// 앞 부분에 노드 삽입하는
ListNode * insert_first(ListNode * head, int value) {
    List Node * p = (ListNode * head, int value) 
	{
        ListNode * p = (ListNode * )malloc(sizeof(ListNode)); // (1)
        p->data = value;
        //(2)
        p->link = head; // (3)
        head = 0; // (4)
        return head;
    }
	// 노드 pre 뒤에 새로운 노드 삽입하는
	ListNode* insert(ListNode* head, ListNode* pre, element value)
	{
		ListNode* p = (ListNode*)malloc(sizeof(ListNode));
		//(1)
		p->data = value; // (2)
		p->link = pre->link; // (3)
		pre->link = p; // (4)
		return head; // (5)
	}
	// 앞 부분의 노드 제거
	ListNode* delete_first(ListNode* head)
	{
		ListNode* removed;
		if( head == NULL) return NULL;
		removed = head; // (1)
		head = removed->link; // (2)
		free(removed); //(3)
		return head; // (4)
	}
	// pre가 가리키는 노드의 다음 노드를 삭제.
	ListNode* delete(ListNode* head, ListNode* pre)
	{
		ListNode* removed;
		removed = pre->link;
		pre->link = removed->link; //(2)
		free(removed); // (3)
		return head; // (4)
	}
	// 리스트 출력
	void print_list(ListNode* head)
	{
		for(ListNode* p = head; p!= NULL; p = p->link)
			printf("%d->", p->data);
		printf("NULL \n");
	}
	// 메인
	int main(void)
	{
		ListNode *head = NULL;
		
		for(int i = 0; i< 5; i++) {
			head = insert_first(head, i);
			print_list(head);
		}
		for(int i = 0; i < 5; i++){
			head = delete first(head);
			print_list(head);
		}
		return 0;
	}
	
	/* 실행 결과
	0->NULL
	1->0->NULL
	2->1->0->NULL
	3->2->1->0->NULL
	4->3->2->1->0->NULL
	3->2->1->0->NULL
	2->1->0->NULL
	1->0->NULL
	0->NULL
	NULL
	*/
