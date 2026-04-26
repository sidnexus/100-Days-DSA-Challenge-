/* Floyd Warshall Algorithm for All-Pairs Shortest Path */

#include <stdio.h>

#define INF 1000000000

int main() {

    int n;
    scanf("%d", &n);

    int dist[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            int x;
            scanf("%d", &x);

            if (i == j)
                dist[i][j] = 0;
            else if (x == -1)
                dist[i][j] = INF;
            else
                dist[i][j] = x;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
