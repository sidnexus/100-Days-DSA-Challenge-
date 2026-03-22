#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct deque {
    struct node *front;
    struct node *rear;
    int size;
};

struct deque* createDeque() {
    struct deque *dq = (struct deque*)malloc(sizeof(struct deque));
    dq->front = NULL;
    dq->rear = NULL;
    dq->size = 0;
    return dq;
}

void push_front(struct deque *dq, int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = dq->front;
    if(dq->front != NULL)
        dq->front->prev = newnode;
    dq->front = newnode;
    if(dq->rear == NULL)
        dq->rear = newnode;
    dq->size++;
}

void push_back(struct deque *dq, int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = dq->rear;
    if(dq->rear != NULL)
        dq->rear->next = newnode;
    dq->rear = newnode;
    if(dq->front == NULL)
        dq->front = newnode;
    dq->size++;
}

void pop_front(struct deque *dq) {
    if(dq->front == NULL) return;
    struct node *temp = dq->front;
    dq->front = dq->front->next;
    if(dq->front != NULL)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;
    free(temp);
    dq->size--;
}

void pop_back(struct deque *dq) {
    if(dq->rear == NULL) return;
    struct node *temp = dq->rear;
    dq->rear = dq->rear->prev;
    if(dq->rear != NULL)
        dq->rear->next = NULL;
    else
        dq->front = NULL;
    free(temp);
    dq->size--;
}

int front(struct deque *dq) {
    if(dq->front == NULL) return -1;
    return dq->front->data;
}

int back(struct deque *dq) {
    if(dq->rear == NULL) return -1;
    return dq->rear->data;
}

bool empty(struct deque *dq) {
    return dq->size == 0;
}

int size(struct deque *dq) {
    return dq->size;
}

void display(struct deque *dq) {
    struct node *temp = dq->front;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void clear(struct deque *dq) {
    while(dq->front != NULL) {
        pop_front(dq);
    }
}

int main() {
    struct deque *dq = createDeque();
    push_back(dq, 10);
    push_back(dq, 20);
    push_front(dq, 5);
    display(dq);
    pop_front(dq);
    display(dq);
    push_back(dq, 30);
    pop_back(dq);
    display(dq);
    printf("%d %d %d\n", front(dq), back(dq), size(dq));
    clear(dq);
    printf("%d\n", empty(dq));
    return 0;
}
