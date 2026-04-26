/* Program to detect cycle in a directed graph using DFS and recursion stack */

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
int recStack[1000];

int dfs(int node, struct Node* adj[]) {
    visited[node] = 1;
    recStack[node] = 1;

    struct Node* temp = adj[node];

    while (temp != NULL) {
        int v = temp->vertex;

        if (!visited[v]) {
            if (dfs(v, adj))
                return 1;
        }
        else if (recStack[v]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[node] = 0;
    return 0;
}

int main() {
    int n, m;

    scanf("%d", &n);   // vertices
    scanf("%d", &m);   // edges

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

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}
