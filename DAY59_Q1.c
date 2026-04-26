/* Program to construct binary tree from inorder and postorder and print preorder */

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

int mapIndex[1000];

void buildMap(int inorder[], int n) {
    for (int i = 0; i < n; i++)
        mapIndex[inorder[i]] = i;
}

struct Node* buildTree(int inorder[], int postorder[], int start, int end) {
    if (start > end)
        return NULL;

    int curr = postorder[postIndex--];
    struct Node* root = createNode(curr);

    if (start == end)
        return root;

    int pos = mapIndex[curr];

    root->right = buildTree(inorder, postorder, pos + 1, end);
    root->left  = buildTree(inorder, postorder, start, pos - 1);

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n, i;

    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    buildMap(inorder, n);

    postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1);

    preorder(root);

    return 0;
}
