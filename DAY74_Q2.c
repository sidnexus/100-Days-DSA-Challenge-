/* Number of Provinces using DFS */

#include <stdio.h>

int n;
int vis[200];
int a[200][200];

void dfs(int node) {
    vis[node] = 1;

    for (int i = 0; i < n; i++) {
        if (a[node][i] == 1 && !vis[i]) {
            dfs(i);
        }
    }
}

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        vis[i] = 0;

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
