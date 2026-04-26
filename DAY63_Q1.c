/* Program to perform DFS traversal from a given source vertex */

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

void dfs(int s, struct Node* adj[]) {
    visited[s] = 1;
    printf("%d ", s);

    struct Node* temp = adj[s];

    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex, adj);
        }
        temp = temp->next;
    }
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

    int s;
    scanf("%d", &s);   // starting vertex

    dfs(s, adj);

    return 0;
}
