/* Construct binary tree from inorder & postorder and print level order */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

int postIndex;

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct Node* buildTree(int inorder[], int postorder[], int start, int end) {
    if (start > end)
        return NULL;

    int curr = postorder[postIndex--];
    struct Node* root = createNode(curr);

    if (start == end)
        return root;

    int pos = search(inorder, start, end, curr);

    root->right = buildTree(inorder, postorder, pos + 1, end);
    root->left  = buildTree(inorder, postorder, start, pos - 1);

    return root;
}

void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left != NULL)
            queue[rear++] = temp->left;

        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

int main() {
    int n, i;

    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1);

    levelOrder(root);

    return 0;
}
