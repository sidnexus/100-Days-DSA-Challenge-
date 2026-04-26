/* Program to print Topological Sort of a DAG using DFS */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->vertex = v;
    n->next = NULL;
    return n;
}

int visited[1000];
int stack[1000];
int top = -1;

void dfs(int node, struct Node* adj[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];

    while (temp != NULL) {
        int v = temp->vertex;

        if (!visited[v]) {
            dfs(v, adj);
        }

        temp = temp->next;
    }

    stack[++top] = node;
}

int main() {
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj);
        }
    }

    while (top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
