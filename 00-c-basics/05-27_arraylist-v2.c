#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LIST_SIZE 100

typedef char* element;
typedef struct listNode {
   element data;
   struct listNode* link;
} ListNode;

typedef struct {
   element array[MAX_LIST_SIZE];
   int size;
} ArrayListType;

void error(char* message) {
   fprintf(stderr, "%s\n", message);
   exit(1);
}

void init(ArrayListType* L) {
   L->size = 0;
}

int is_full(ArrayListType* L) {
   return (L->size == MAX_LIST_SIZE);
}

void insert(ArrayListType* L, int pos, element item) {
   if (is_full(L)) {
      error("리스트 오버플로우");
      return;
   }
   if (pos < 0 || pos > L->size) {
      error("위치 오류");
      return;
   }

   for (int i = L->size - 1; i >= pos; i--) {
      L->array[i + 1] = L->array[i];
   }
   L->array[pos] = strdup(item);
   if (L->array[pos] == NULL) {
       error("메모리 할당 실패");
   }
   L->size++;
}

void insert_last(ArrayListType* L, element item) {
   if (is_full(L)) {
      error("리스트 오버플로우");
   }
   L->array[L->size++] = strdup(item);
   if (L->array[L->size - 1] == NULL) {
       error("메모리 할당 실패");
   }
}

void insert_first(ArrayListType* L, element item) {
   insert(L, 0, item);
}

void clear(ArrayListType* L) {
   for (int i = 0; i < L->size; i++) {
      free(L->array[i]);
   }
   init(L);
}

element get_entry(ArrayListType* L, int pos) {
   if (pos >= 0 && pos < L->size) {
      return L->array[pos];
   } else {
      error("위치 오류");
      return NULL;
   }
}

int get_length(ArrayListType* L) {
   return L->size;
}

int is_empty(ArrayListType* L) {
   return (L->size == 0);
}

void print_list(ArrayListType* L) {
   for (int i = 0; i < L->size; i++) {
      printf("%s -> ", L->array[i]);
   }
   printf("NULL\n");
}

void delete_item(ArrayListType* L, int pos) {
   if (pos < 0 || pos >= L->size) {
      error("위치 오류");
      return;
   }

   free(L->array[pos]);

   for (int i = pos; i < L->size - 1; i++) {
      L->array[i] = L->array[i + 1];
   }
   L->size--;
}

ListNode* search_list(ListNode* h, element x) {
   ListNode* p = h;

   while (p != NULL) {
      if (strcmp(p->data, x) == 0) break;
      p = p->link;
   }
   return p;
}

void insert_to_delete_list(ArrayListType* L, element item) {
   insert_last(L, item);
}

int main(void) {
   int choice;
   char item[100];
   int pos;
   ArrayListType list;
   ArrayListType delete_list;
   init(&list);
   init(&delete_list);
   insert_first(&list, "Peach");
   insert_first(&list, "Banana");
   insert_first(&list, "Raspberry");
   insert_first(&list, "Guava");
   insert_first(&list, "Plum");
   insert_first(&list, "Cherry");
   insert_first(&list, "Grape");
   insert_first(&list, "Apple");
   insert_first(&list, "Orange");
   insert_first(&list, "Mango");

   while (1) {
      printf("\n메뉴 : \n");
      printf("1. 리스트에 추가 \n");
      printf("2. 리스트에서 삭제 \n");
      printf("3. 삭제된 리스트 출력 \n");
      printf("4. 프로그램 종료 \n");
      printf("선택 : ");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
         if (is_full(&list)) {
            printf("리스트가 꽉 찼습니다.\n");
         } else {
            printf("문자열을 입력하세요: ");
            scanf("%s", item);
            insert_last(&list, item);
         }
         break;
      case 2:
         if (is_empty(&list)) {
            printf("리스트가 비어있습니다.\n");
         } else {
            printf("삭제할 문자의 위치를 입력하세요: ");
            scanf("%d", &pos);
            if (pos >= 0 && pos < list.size) {
               insert_to_delete_list(&delete_list, list.array[pos]);
               delete_item(&list, pos);
            } else {
               printf("잘못된 위치입니다.\n");
            }
         }
         break;
      case 3:
         printf("삭제된 리스트: ");
         print_list(&delete_list);
         break;
      case 4:
         printf("프로그램 종료\n");
         clear(&list);
         clear(&delete_list);
         return 0;
      default:
         printf("잘못된 선택입니다. 다시 시도하세요\n");
      }
   }
}
