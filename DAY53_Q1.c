/* Program to print vertical order traversal of a binary tree */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Pair {
    struct Node* node;
    int hd;
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

void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Pair* queue = (struct Pair*)malloc(1000 * sizeof(struct Pair));
    int front = 0, rear = 0;

    int map[200][200];
    int count[200] = {0};

    int offset = 100;

    queue[rear++] = (struct Pair){root, 0};

    while (front < rear) {
        struct Pair p = queue[front++];
        struct Node* temp = p.node;
        int hd = p.hd;

        map[hd + offset][count[hd + offset]++] = temp->data;

        if (temp->left != NULL)
            queue[rear++] = (struct Pair){temp->left, hd - 1};

        if (temp->right != NULL)
            queue[rear++] = (struct Pair){temp->right, hd + 1};
    }

    for (int i = 0; i < 200; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n, i;

    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
