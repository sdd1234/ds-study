#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
  element data;
  struct DListNode *llink, * rlink;
} DListNode;

void init(DListNode* phead) {
  phead->llink = phead->rlink = phead;
}

void dinsert(DListNode* before, element data) {

  DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));  //<1>
  newnode->data = data;  // <1>
  newnode->llink = before;  // <2>
  newnode->rlink = before->rlink; // <3>
//	before->rlink->llink = newnode; // <5>
//	before->rlink = newnode; // <4>
  before->rlink = newnode; // <4>
  newnode->rlink->llink = newnode; // <5>
}

void print_dlist(DListNode* head) {
  DListNode* p;
  for (p = head->rlink; p != head; p = p->rlink) {
    printf(" [%2d] ", p->data);
  }
  printf("\n");
}

element ddelete(DListNode* head, DListNode* removed) {
  element r;
  if (removed == head) return;
  r = removed->data;

  removed->llink->rlink = removed->rlink;
  removed->rlink->llink = removed->llink;
  return r;
}

main()
{
  DListNode* head = (DListNode*)malloc(sizeof(DListNode));
  init(head);
 int num, choice;

  while (1) {
    printf("\n메뉴 : \n");
    printf("1. 처음 리스트추가 \n");
    printf("2. 마지막 리스트추가 \n");
    printf("3. 처음 리스트삭제 \n");
    printf("4. 마지막 리스트삭제 \n");
    printf("5. 리스트 출력 \n");
    printf("6. 종료 \n");
    printf("선택 : ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("삽입할 숫자를 입력하세요: ");
        scanf("%d", &num);
         dinsert(head, num); 
        break;
      case 2:
        printf("삽입할 숫자를 입력하세요: ");
        scanf("%d", &num);
         dinsert(head->llink, num); 
        break;
      case 3:
         ddelete(head,head->rlink); 
        break;
      case 4:
        ddelete(head,head->llink); 
        break;
      case 5:
          print_dlist(head);
        break;
      case 6:
        printf("프로그램 종료\n");
        return 0;
      default:
        printf("잘못된 선택입니다. 다시 시도하세요\n");
    }
  }
  return 0;
}
