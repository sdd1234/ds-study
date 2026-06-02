#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
    element data;
    struct listNode* link;
} ListNode;

ListNode* insert_first(ListNode* h, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = h;
    return p; 
}

ListNode* delete_first(ListNode* h) {
    if (h == NULL) return NULL;
    ListNode* remove = h;
    h = remove->link;
    free(remove);
    return h;
}

ListNode* insert(ListNode* head, int pos, element value) {
    int count = 0;
    ListNode* p = head;
    ListNode* pre = NULL;


    for (int i = 0; i < pos && p != NULL; i++) {
        pre = p;
        p = p->link;
        count++;
    }

  
    if (pos < 0 || (pos > 0 && p == NULL)) {
        return NULL; 
    }

    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = value;
    newNode->link = p;

    if (pre == NULL) { 
        head = newNode;
    } else {
        pre->link = newNode;
    }

    return head;
}

ListNode* delete_item(ListNode* h, int pos) {
    int count = 0;
    ListNode* p = h;
    ListNode* pre = NULL;

    
    for (int i = 0; i < pos && p != NULL; i++) {
        pre = p;
        p = p->link;
        count++;
    }

    
    if (pos < 0 || (pos > 0 && p == NULL)) {
        return h; 

    if (pre == NULL) { 
        h = delete_first(h);
    } else {
        pre->link = p->link;
        free(p);
    }

    return h;
}

void print_list(ListNode* h) {
    while (h != NULL) {
        printf("[%d] ", h->data);
        h = h->link;
    }
    printf("\n");
}

int main() {
    ListNode* head = NULL;
    int choice;
    int count;
    int pos, num;

    while (1) {
        printf("\n메뉴 : \n");
        printf("1. 숫자를 위치에 삽입 \n");
        printf("2. 위치에서 숫자 삭제 \n");
        printf("3. 리스트 출력 \n");
        printf("0. 프로그램 종료 \n");
        printf("선택 : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("삽입할 숫자를 입력하세요: ");
                scanf("%d", &num);
                printf("삽입할 위치를 입력하세요: ");
                scanf("%d", &pos);
                head = insert(head, pos, num);
                if (head != NULL)
                    printf("삽입 완료\n");
                else
                    printf("삽입 실패: 위치가 유효하지 않습니다.\n");
                break;
            case 2:
                printf("삭제할 위치를 입력하세요:");
                scanf("%d", &pos);
                head = delete_item(head, pos);
                if (head != NULL)
                    printf("삭제 완료\n");
                else
                    printf("삭제 실패: 위치가 유효하지 않습니다.\n");
                break;
            case 3:
                print_list(head);
                break;
            case 0:
                printf("프로그램 종료\n");
                return 0;
            default:
                printf("잘못된 선택입니다. 다시 시도하세요\n");
        }
    }
    return 0;
}
