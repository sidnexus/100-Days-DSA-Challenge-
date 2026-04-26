/* Optimized program to build tree from preorder & inorder and print postorder */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

int preIndex = 0;

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

struct Node* buildTree(int preorder[], int inorder[], int start, int end) {
    if (start > end)
        return NULL;

    int curr = preorder[preIndex++];
    struct Node* root = createNode(curr);

    if (start == end)
        return root;

    int pos = mapIndex[curr];

    root->left = buildTree(preorder, inorder, start, pos - 1);
    root->right = buildTree(preorder, inorder, pos + 1, end);

    return root;
}

void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n, i;

    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    buildMap(inorder, n);

    struct Node* root = buildTree(preorder, inorder, 0, n - 1);

    postorder(root);

    return 0;
}
