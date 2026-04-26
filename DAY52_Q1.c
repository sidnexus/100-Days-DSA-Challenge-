/* Program to find LCA in a Binary Tree using recursion */

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

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    struct Node* left = findLCA(root->left, n1, n2);
    struct Node* right = findLCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
        return root;

    if (left != NULL)
        return left;
    else
        return right;
}

int main() {
    int n, i, n1, n2;

    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d %d", &n1, &n2);

    struct Node* root = buildTree(arr, n);

    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}
