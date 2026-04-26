/* Clone Graph using DFS */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int val;
    int size;
    struct Node* neighbors[100];
};

struct Node* created[MAX];

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->size = 0;
    return node;
}

struct Node* dfs(struct Node* node) {

    if (node == NULL)
        return NULL;

    if (created[node->val] != NULL)
        return created[node->val];

    struct Node* copy = createNode(node->val);
    created[node->val] = copy;

    for (int i = 0; i < node->size; i++) {
        copy->neighbors[copy->size++] = dfs(node->neighbors[i]);
    }

    return copy;
}

int main() {

    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("[]");
        return 0;
    }

    for (int i = 0; i < MAX; i++)
        created[i] = NULL;

    struct Node* nodes[MAX];

    for (int i = 1; i <= n; i++)
        nodes[i] = createNode(i);

    for (int i = 1; i <= n; i++) {
        int x;
        while (1) {
            scanf("%d", &x);
            if (x == -1) break;
            nodes[i]->neighbors[nodes[i]->size++] = nodes[x];
        }
    }

    struct Node* clone = dfs(nodes[1]);

    printf("Graph Cloned");

    return 0;
}
