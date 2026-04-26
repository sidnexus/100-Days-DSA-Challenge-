/* Bellman-Ford Algorithm: shortest path + negative cycle detection */

#include <stdio.h>
#include <limits.h>

#define INF 1000000000

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    int u[m], v[m], w[m];

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    int src;
    scanf("%d", &src);

    int dist[n];

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }

    int cycle = 0;

    for (int j = 0; j < m; j++) {
        if (dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
            cycle = 1;
            break;
        }
    }

    if (cycle) {
        printf("NEGATIVE CYCLE");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d ", dist[i]);
        }
    }

    return 0;
}
