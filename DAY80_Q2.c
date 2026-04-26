/* Find City With Smallest Number of Neighbors within Threshold */

#include <stdio.h>

#define MAX 105
#define INF 1000000000

int dist[MAX][MAX];

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize distances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        if (w < dist[u][v]) {
            dist[u][v] = w;
            dist[v][u] = w;
        }
    }

    int threshold;
    scanf("%d", &threshold);

    // Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int minCount = INF;
    int resultCity = -1;

    for (int i = 0; i < n; i++) {

        int count = 0;

        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= threshold)
                count++;
        }

        if (count < minCount || (count == minCount && i > resultCity)) {
            minCount = count;
            resultCity = i;
        }
    }

    printf("%d", resultCity);

    return 0;
}
