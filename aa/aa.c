// Algorithm Analysis
// �� ���� (Heap Sort) : �� ������ ����Ͽ� �����͸� �����Ѵ�

#include <stdio.h>

int size = 8;
int heap[8] = { 6, 5, 3, 1, 8, 7, 2, 4 };

int BinarySearch(int dataArr[], int size, int findData);

int main() {
    // Ʈ�� ������ �ִ� �� ������ ��ȯ
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
    // �� ũ�⸦ ���̸鼭 �ݺ������� ���� ����
    for (int i = size - 1; i >= 0; i--) {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int child = 1;
        do {
            child = 2 * root + 1;
            // �ڽ� �� �� ū ���� ã��
            if (heap[child] < heap[child + 1] && child < i - 1) {
                child++;
            }
            // root���� �ڽ��� �� ũ�� ��ȯ
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
        printf("%d��°\n", heap[a]);
    else
        printf("Ž�� ����\n");

    return 0;
}

int BinarySearch(int dataArr[], int size, int findData)
{
    int low = 0, high = size - 1, mid;

    // high�� low���� �۾����ٸ� ã������ �����Ͱ� ������ ���տ� ����.
    while (low <= high)
    {
        // �߾Ӱ��� low�� high�� ���� ���� 2�� ������ �ȴ�.
        mid = (low + high) / 2;
        // ���� ã������ ���� �߾Ӱ����� �۴ٸ� high�� mid - 1�� �д�.
        if (dataArr[mid] > findData) high = mid - 1;
        // ���� ã������ ���� �߾Ӱ����� ũ�ٸ� low�� mid + 1�� �д�.
        else if (dataArr[mid] < findData) low = mid + 1;
        // �߾Ӱ��� ã������ ���� ��ġ�ϸ� mid�� ��ȯ�Ѵ�.
        else return mid;
    }
    // �����͸� ã�� ���ϸ� -1�� ��ȯ�Ѵ�.
    return -1;
}