/* Count Connected Components in Undirected Graph using DFS */

#include <stdio.h>

int adj[1000][1000];
int size[1000];
int visited[1000];

void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int v = adj[node][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        size[i] = 0;
        visited[i] = 0;
    }

    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
