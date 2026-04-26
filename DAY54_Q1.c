/* Program to perform zigzag (spiral) level order traversal */

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

void zigzagTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node** queue = (struct Node**)malloc(2000 * sizeof(struct Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int tempArr[size];

        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];

            tempArr[i] = curr->data;

            if (curr->left != NULL)
                queue[rear++] = curr->left;

            if (curr->right != NULL)
                queue[rear++] = curr->right;
        }

        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", tempArr[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", tempArr[i]);
        }

        leftToRight = !leftToRight;
    }
}

int main() {
    int n, i;

    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}
