#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapifyDown(int *heap, int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void heapifyUp(int *heap, int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (heap[parent] > heap[index]) {
        swap(&heap[parent], &heap[index]);
        heapifyUp(heap, parent);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    int *heap = (int*)malloc(sizeof(int) * k);
    int heapSize = 0;

    for (int i = 0; i < numsSize; i++) {
        if (heapSize < k) {
            heap[heapSize] = nums[i];
            heapifyUp(heap, heapSize);
            heapSize++;
        } else if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            heapifyDown(heap, heapSize, 0);
        }
    }

    int result = heap[0];
    free(heap);
    return result;
}