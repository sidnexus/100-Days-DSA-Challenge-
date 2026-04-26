/* Find Articulation Points in Graph using Tarjan's Algorithm */

#include <stdio.h>

#define MAX 100005

int adj[MAX][10];
int size[MAX];

int disc[MAX], low[MAX], visited[MAX];
int isAP[MAX];

int timeCounter = 0;

void dfs(int u, int parent) {

    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    int children = 0;

    for (int i = 0; i < size[u]; i++) {

        int v = adj[u][i];

        if (!visited[v]) {

            children++;
            dfs(v, u);

            if (low[v] < low[u])
                low[u] = low[v];

            if (parent != -1 && low[v] >= disc[u])
                isAP[u] = 1;
        }
        else if (v != parent) {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }

    if (parent == -1 && children > 1)
        isAP[u] = 1;
}

int main() {

    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        isAP[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    int found = 0;

    for (int i = 0; i < V; i++) {
        if (isAP[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("-1");

    return 0;
}
