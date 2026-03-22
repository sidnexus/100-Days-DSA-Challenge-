#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    if(val==-1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Queue {
    struct Node* arr[1000];
    int front,rear;
};

void enqueue(struct Queue* q, struct Node* node){ q->arr[++q->rear]=node; }
struct Node* dequeue(struct Queue* q){ return q->arr[q->front++]; }
int isEmpty(struct Queue* q){ return q->front>q->rear; }

int main() {
    int N;
    scanf("%d",&N);
    int vals[N];
    for(int i=0;i<N;i++) scanf("%d",&vals[i]);

    struct Node* root = createNode(vals[0]);
    struct Queue q; q.front=0; q.rear=-1;
    if(root) enqueue(&q,root);

    int i=1;
    while(i<N && !isEmpty(&q)){
        struct Node* curr=dequeue(&q);
        if(i<N){ curr->left=createNode(vals[i++]); if(curr->left) enqueue(&q,curr->left);}
        if(i<N){ curr->right=createNode(vals[i++]); if(curr->right) enqueue(&q,curr->right);}
    }

    struct Queue levelQ; levelQ.front=0; levelQ.rear=-1;
    if(root) enqueue(&levelQ,root);
    while(!isEmpty(&levelQ)){
        int sz = levelQ.rear - levelQ.front + 1;
        printf("[");
        for(int j=0;j<sz;j++){
            struct Node* curr = dequeue(&levelQ);
            printf("%d",curr->data);
            if(j<sz-1) printf(",");
            if(curr->left) enqueue(&levelQ,curr->left);
            if(curr->right) enqueue(&levelQ,curr->right);
        }
        printf("]");
        if(!isEmpty(&levelQ)) printf(",");
    }
    return 0;
}
