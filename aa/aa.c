// Algorithm Analysis
// 힙 정렬 (Heap Sort) : 힙 구조를 사용하여 데이터를 정렬한다

#include <stdio.h>

int size = 8;
int heap[8] = { 6, 5, 3, 1, 8, 7, 2, 4 };

int BinarySearch(int dataArr[], int size, int findData);

int main() {
    // 트리 구조를 최대 힙 구조로 변환
    for (int i = 1; i < size; i++) {
        int child = i;
        do {
            int root = (child - 1) / 2;
            if (heap[root] < heap[child]) {
                int temp = heap[root];
                heap[root] = heap[child];
                heap[child] = temp;
            }
            child = root;
        } while (child != 0);
    }
    // 힙 크기를 줄이면서 반복적으로 힙을 구성
    for (int i = size - 1; i >= 0; i--) {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int child = 1;
        do {
            child = 2 * root + 1;
            // 자식 중 더 큰 값을 찾기
            if (heap[child] < heap[child + 1] && child < i - 1) {
                child++;
            }
            // root보다 자식이 더 크면 교환
            if (heap[root] < heap[child] && child < i) {
                int temp = heap[root];
                heap[root] = heap[child];
                heap[child] = temp;
            }
            root = child;
        } while (child < i);
    }
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);

    printf("\n");

    int num;
    scanf("%d", &num);

    int a = BinarySearch(heap, size, num);
    if (a != -1)
        printf("%d번째\n", heap[a]);
    else
        printf("탐색 실패\n");

    return 0;
}

int BinarySearch(int dataArr[], int size, int findData)
{
    int low = 0, high = size - 1, mid;

    // high가 low보다 작아진다면 찾으려는 데이터가 데이터 집합에 없다.
    while (low <= high)
    {
        // 중앙값은 low와 high를 더한 값을 2로 나누면 된다.
        mid = (low + high) / 2;
        // 만약 찾으려는 값이 중앙값보다 작다면 high를 mid - 1로 둔다.
        if (dataArr[mid] > findData) high = mid - 1;
        // 만약 찾으려는 값이 중앙값보다 크다면 low를 mid + 1로 둔다.
        else if (dataArr[mid] < findData) low = mid + 1;
        // 중앙값과 찾으려는 값이 일치하면 mid를 반환한다.
        else return mid;
    }
    // 데이터를 찾지 못하면 -1를 반환한다.
    return -1;
}