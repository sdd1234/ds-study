#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) { //스왑함수
    int temp = *a;
    *a = *b;
    *b = temp;
}
void resortHeap(int inputData[], int n, int i) {//힙으로 정렬
    int large = i;             
    int left = 2 * i + 1;      
    int right = 2 * i + 2;      
    if (left < n && inputData[left] > inputData[large]) {
        large = left;
    }
    if (right < n && inputData[right] > inputData[large]) {
        large = right;
    }
    if (large != i) {
        swap(&inputData[i], &inputData[large]);
        resortHeap(inputData, n, large);
    }
}

void BuildMaxHeap(int inputData[], int size) {//최대 힙을만드는함수
	for (int i = size / 2 - 1; i >= 0; i--) { //배열의 개수가 17개이고 17/2-1=7이므로 7부터 시작해서 0까지 감소하면서 최대힙을 만든다.
        resortHeap(inputData, size, i);
    }
}
void BuildMaxHeapAndSort(int inputData[], int n) {// 최대 힙 만들고 정렬 한다음 출력
 for (int i = 1; i <= n; i++) {
        BuildMaxHeap(inputData, i); 

       for (int j = 0; j < i; j++) {
            printf("%d ", inputData[j]);//전체출력
        }
        printf("\n");
    }
       for (int i = n - 1; i > 0; i--) {
        swap(&inputData[0], &inputData[i]);    
        resortHeap(inputData, i, 0);           
    for (int j = 0; j < i; j++) {
            printf("%d ", inputData[j]); //작아지면서 출력
        }
        printf("\n");
    }
}

int main() {
    int inputData[] = { 34, 12, 76, 59, 32, 55, 88, 26, 16, 79, 35, 85, 29, 78, 41, 56, 86 };
    int size = sizeof(inputData) / sizeof(inputData[0]);
    printf("<Sort>\n");
    BuildMaxHeapAndSort(inputData, size);
    printf("\nSorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", inputData[i]);
    }
    printf("\n");
    return 0;
}