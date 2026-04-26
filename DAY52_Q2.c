/* Program to find Lowest Common Ancestor (LCA) in a Binary Tree */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int v) {
    struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    n->val = v;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    struct TreeNode* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct TreeNode* temp = queue[front++];

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

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL)
        return NULL;

    if (root == p || root == q)
        return root;

    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    if (left != NULL)
        return left;
    else
        return right;
}

struct TreeNode* findNode(struct TreeNode* root, int val) {
    if (root == NULL)
        return NULL;

    if (root->val == val)
        return root;

    struct TreeNode* left = findNode(root->left, val);
    if (left != NULL)
        return left;

    return findNode(root->right, val);
}

int main() {
    int n, i, v1, v2;

    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d %d", &v1, &v2);

    struct TreeNode* root = buildTree(arr, n);

    struct TreeNode* p = findNode(root, v1);
    struct TreeNode* q = findNode(root, v2);

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL)
        printf("%d", lca->val);

    return 0;
}
