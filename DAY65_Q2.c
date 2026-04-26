/* Program to detect cycle in undirected graph using edge list input */

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

int visited[100000];

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
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[V];

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    int u, v;

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);

        struct Node* n1 = createNode(v);
        n1->next = adj[u];
        adj[u] = n1;

        struct Node* n2 = createNode(u);
        n2->next = adj[v];
        adj[v] = n2;
    }

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int hasCycle = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("true");
    else
        printf("false");

    return 0;
}
