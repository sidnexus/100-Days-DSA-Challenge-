/* Count Strongly Connected Components using Kosaraju's Algorithm */

#include <stdio.h>

#define MAX 100005

int adj[MAX][10], size[MAX];
int rev[MAX][10], rsize[MAX];

int visited[MAX];
int stack[MAX], top = -1;

void dfs1(int u) {

    visited[u] = 1;

    for (int i = 0; i < size[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs1(v);
        }
    }

    stack[++top] = u;
}

void dfs2(int u) {

    visited[u] = 1;

    for (int i = 0; i < rsize[u]; i++) {
        int v = rev[u][i];
        if (!visited[v]) {
            dfs2(v);
        }
    }
}

int main() {

    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v;
        rev[v][rsize[v]++] = u;
    }

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int count = 0;

    while (top != -1) {
        int node = stack[top--];

        if (!visited[node]) {
            dfs2(node);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
