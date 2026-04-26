/* Program to flatten a binary tree into a linked list (preorder) */

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
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* temp = queue[front++];

        if (arr[i] != -1) {
            temp->left = createNode(arr[i]);
            queue[rear++] = temp->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            temp->right = createNode(arr[i]);
            queue[rear++] = temp->right;
        }
        i++;
    }

    return root;
}

void flatten(struct Node* root) {
    if (root == NULL)
        return;

    flatten(root->left);
    flatten(root->right);

    if (root->left != NULL) {
        struct Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        struct Node* curr = root->right;
        while (curr->right != NULL)
            curr = curr->right;

        curr->right = temp;
    }
}

void printList(struct Node* root) {
    while (root != NULL) {
        printf("%d ", root->data);
        root = root->right;
    }
}

int main() {
    int n, i;

    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    flatten(root);

    printList(root);

    return 0;
}
