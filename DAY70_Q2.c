/* Cheapest Flights Within K Stops using Bellman-Ford style DP */

#include <stdio.h>

#define INF 1000000000

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    int flights[m][3];

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &flights[i][0], &flights[i][1], &flights[i][2]);
    }

    int src, dst, k;
    scanf("%d %d %d", &src, &dst, &k);

    int dist[n];

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    int temp[n];

    for (int i = 0; i <= k; i++) {

        for (int j = 0; j < n; j++)
            temp[j] = dist[j];

        for (int j = 0; j < m; j++) {

            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];

            if (dist[u] != INF && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }

        for (int j = 0; j < n; j++)
            dist[j] = temp[j];
    }

    if (dist[dst] == INF)
        printf("-1");
    else
        printf("%d", dist[dst]);

    return 0;
}
