#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int heap[1000];
int size = 0;

void heapifyUp(int index) {
    while(index > 0) {
        int parent = (index - 1) / 2;
        if(heap[parent] > heap[index]) {
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
            index = parent;
        } else break;
    }
}

void heapifyDown(int index) {
    while(2*index + 1 < size) {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int smallest = index;
        if(left < size && heap[left] < heap[smallest])
            smallest = left;
        if(right < size && heap[right] < heap[smallest])
            smallest = right;
        if(smallest != index) {
            int temp = heap[smallest];
            heap[smallest] = heap[index];
            heap[index] = temp;
            index = smallest;
        } else break;
    }
}

void insert(int val) {
    heap[size++] = val;
    heapifyUp(size - 1);
}

int extractMin() {
    if(size == 0) return -1;
    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return min;
}

int peek() {
    if(size == 0) return -1;
    return heap[0];
}

int main() {
    int N;
    scanf("%d", &N);
    char op[20];
    int val;
    for(int i = 0; i < N; i++) {
        scanf("%s", op);
        if(strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if(strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } else if(strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }
    return 0;
}
