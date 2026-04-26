/* Program to find number of provinces (connected components) */

#include <stdio.h>

int n;
int visited[200];

void dfs(int city, int adj[200][200]) {
    visited[city] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[city][i] == 1 && !visited[i]) {
            dfs(i, adj);
        }
    }
}

int main() {
    scanf("%d", &n);

    int adj[200][200];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
