#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;
    if(q->rear == NULL) {
        q->front = q->rear = newnode;
        return;
    }
    q->rear->next = newnode;
    q->rear = newnode;
}

int dequeue(struct Queue* q) {
    if(q->front == NULL)
        return -1;
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if(q->front == NULL)
        q->rear = NULL;
    free(temp);
    return val;
}

int main() {
    int N;
    scanf("%d", &N);
    struct Queue* q = createQueue();
    char op[20];
    int val;
    for(int i = 0; i < N; i++) {
        scanf("%s", op);
        if(op[0] == 'e') {
            scanf("%d", &val);
            enqueue(q, val);
        } else if(op[0] == 'd') {
            printf("%d\n", dequeue(q));
        }
    }
    return 0;
}
