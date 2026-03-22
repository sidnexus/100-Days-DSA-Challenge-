#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* deque = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    deque->arr = (int*)malloc(sizeof(int) * k);
    deque->front = 0;
    deque->rear = 0;
    deque->size = 0;
    deque->capacity = k;
    return deque;
}

bool insertFront(MyCircularDeque* obj, int value) {
    if(obj->size == obj->capacity)
        return false;
    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->arr[obj->front] = value;
    obj->size++;
    return true;
}

bool insertLast(MyCircularDeque* obj, int value) {
    if(obj->size == obj->capacity)
        return false;
    obj->arr[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->size++;
    return true;
}

bool deleteFront(MyCircularDeque* obj) {
    if(obj->size == 0)
        return false;
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}

bool deleteLast(MyCircularDeque* obj) {
    if(obj->size == 0)
        return false;
    obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    obj->size--;
    return true;
}

int getFront(MyCircularDeque* obj) {
    if(obj->size == 0)
        return -1;
    return obj->arr[obj->front];
}

int getRear(MyCircularDeque* obj) {
    if(obj->size == 0)
        return -1;
    return obj->arr[(obj->rear - 1 + obj->capacity) % obj->capacity];
}

bool isEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

bool isFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}

int main()
{
    MyCircularDeque* deque = myCircularDequeCreate(3);
    printf("%d\n", insertLast(deque, 1));
    printf("%d\n", insertLast(deque, 2));
    printf("%d\n", insertFront(deque, 3));
    printf("%d\n", insertFront(deque, 4));
    printf("%d\n", getRear(deque));
    printf("%d\n", isFull(deque));
    printf("%d\n", deleteLast(deque));
    printf("%d\n", insertFront(deque, 4));
    printf("%d\n", getFront(deque));
    myCircularDequeFree(deque);
    return 0;
}
