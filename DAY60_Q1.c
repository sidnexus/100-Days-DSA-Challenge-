/* Program to check whether a binary tree satisfies Min-Heap property */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0)
        return NULL;

    struct Node* queue[2000];
    int front = 0, rear = 0;

    struct Node* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* temp = queue[front++];

        if (i < n) {
            temp->left = createNode(arr[i++]);
            queue[rear++] = temp->left;
        }

        if (i < n) {
            temp->right = createNode(arr[i++]);
            queue[rear++] = temp->right;
        }
    }

    return root;
}

int isMinHeap(struct Node* root) {
    if (root == NULL)
        return 1;

    if (root->left != NULL) {
        if (root->data > root->left->data)
            return 0;
    }

    if (root->right != NULL) {
        if (root->data > root->right->data)
            return 0;
    }

    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main() {
    int n, i;

    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if (isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}
