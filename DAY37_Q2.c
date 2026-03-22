#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int k;
    int *arr;
    int size;
    int capacity;
} KthLargest;

KthLargest* KthLargestCreate(int k, int* nums, int n) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->k = k;
    obj->capacity = n + 1000;
    obj->arr = (int*)malloc(sizeof(int) * obj->capacity);
    for(int i = 0; i < n; i++)
        obj->arr[i] = nums[i];
    obj->size = n;
    return obj;
}

int add(KthLargest* obj, int val) {
    obj->arr[obj->size++] = val;
    for(int i = 0; i < obj->size - 1; i++) {
        for(int j = i + 1; j < obj->size; j++) {
            if(obj->arr[i] < obj->arr[j]) {
                int temp = obj->arr[i];
                obj->arr[i] = obj->arr[j];
                obj->arr[j] = temp;
            }
        }
    }
    return obj->arr[obj->k - 1];
}

void KthLargestFree(KthLargest* obj) {
    free(obj->arr);
    free(obj);
}

int main() {
    int nums[] = {4, 5, 8, 2};
    KthLargest* kth = KthLargestCreate(3, nums, 4);
    printf("%d\n", add(kth, 3));
    printf("%d\n", add(kth, 5));
    printf("%d\n", add(kth, 10));
    printf("%d\n", add(kth, 9));
    printf("%d\n", add(kth, 4));
    KthLargestFree(kth);
    return 0;
}
