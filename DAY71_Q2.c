/* Minimum Cost to Connect Points using Prim's Algorithm */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define INF 1000000000

int absVal(int x) {
    return x < 0 ? -x : x;
}

int dist(int a[2], int b[2]) {
    return absVal(a[0] - b[0]) + absVal(a[1] - b[1]);
}

int main() {
    int n;
    scanf("%d", &n);

    int points[n][2];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    int visited[n];
    int minCost[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        minCost[i] = INF;
    }

    minCost[0] = 0;

    int totalCost = 0;

    for (int i = 0; i < n; i++) {

        int u = -1;
        int min = INF;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && minCost[j] < min) {
                min = minCost[j];
                u = j;
            }
        }

        visited[u] = 1;
        totalCost += min;

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int w = dist(points[u], points[v]);

                if (w < minCost[v]) {
                    minCost[v] = w;
                }
            }
        }
    }

    printf("%d", totalCost);

    return 0;
}
