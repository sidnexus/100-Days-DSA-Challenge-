/* Find Critical Connections (Bridges) in Graph using DFS */

#include <stdio.h>

#define MAX 100005

int adj[MAX][10];
int size[MAX];

int disc[MAX];
int low[MAX];
int visited[MAX];

int timeCounter = 0;

int resU[MAX], resV[MAX], resSize = 0;

void dfs(int u, int parent) {

    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    for (int i = 0; i < size[u]; i++) {

        int v = adj[u][i];

        if (v == parent)
            continue;

        if (!visited[v]) {

            dfs(v, u);

            if (low[v] < low[u])
                low[u] = low[v];

            if (low[v] > disc[u]) {
                resU[resSize] = u;
                resV[resSize] = v;
                resSize++;
            }
        }
        else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    for (int i = 0; i < resSize; i++) {
        printf("[%d,%d]\n", resU[i], resV[i]);
    }

    return 0;
}
