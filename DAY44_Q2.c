#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Stack {
    struct Node* arr[100];
    int top;
};

void push(struct Stack* s, struct Node* node) { s->arr[++s->top]=node; }
struct Node* pop(struct Stack* s) { return s->arr[s->top--]; }
int isEmpty(struct Stack* s) { return s->top==-1; }

void preorder(struct Node* root) {
    if(!root) return;
    struct Stack s; s.top=-1;
    push(&s, root);
    while(!isEmpty(&s)) {
        struct Node* curr = pop(&s);
        printf("%d ", curr->data);
        if(curr->right) push(&s, curr->right);
        if(curr->left) push(&s, curr->left);
    }
}

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    struct Node* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);
    preorder(root);
    return 0;
}
