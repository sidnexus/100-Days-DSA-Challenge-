/* Program to detect cycle in an undirected graph using DFS */

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

int dfs(int node, int parent, struct Node* adj[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];

    while (temp != NULL) {
        int v = temp->vertex;

        if (!visited[v]) {
            if (dfs(v, node, adj))
                return 1;
        }
        else if (v != parent) {
            return 1;
        }

        temp = temp->next;
    }

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

        struct Node* newNode2 = createNode(u);
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj)) {
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
