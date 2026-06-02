#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
  element data;
  struct listNode* link;
} ListNode;

ListNode *insert_first(ListNode* tail, element data) {
  ListNode* node = (ListNode*)malloc(sizeof(ListNode));
  node->data = data;
  if (tail == NULL) {
    tail = node;
    node->link = tail;
  } else {
    node->link = tail->link;
    tail->link = node;
  }
  return tail;
}

void print_list(ListNode* tail) {
  ListNode* p;

  if (tail == NULL) return;
  p = tail->link;
  do {
    printf("[%2d] ", p->data);
    p = p->link;
  } while (p != tail->link);
  printf("\n");
}

ListNode* insert_last(ListNode* tail, element data) {
  ListNode* node = (ListNode*)malloc(sizeof(ListNode));
  node->data = data;

  if (tail == NULL) {
    tail = node;
    node->link = node;
  } else {
    node->link = tail->link;
    tail->link = node;
    tail = node;
  }
  return tail;
}

ListNode* delete_first(ListNode* tail) {
  if (tail == NULL) return NULL;

  ListNode* remove = tail->link;
  if (tail == remove) {
    free(remove);
    return NULL;
  }

  tail->link = remove->link;
  free(remove);
  return tail;
}

ListNode* delete_last(ListNode* tail) {
  if (tail == NULL) return NULL;

  ListNode* current = tail->link;
  if (current == tail) {
    free(tail);
    return NULL;
  }

  while (current->link != tail) {
    current = current->link;
  }

  current->link = tail->link;
  free(tail);
  return current;
}

int main() {
  ListNode* tail = NULL;
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
        tail = insert_first(tail, num); 
        break;
      case 2:
        printf("삽입할 숫자를 입력하세요: ");
        scanf("%d", &num);
        tail = insert_last(tail, num); 
        break;
      case 3:
        tail = delete_first(tail); 
        break;
      case 4:
        tail = delete_last(tail); 
        break;
      case 5:
        print_list(tail);
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
