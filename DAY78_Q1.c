/* Prim's Algorithm to find MST Total Weight */

#include <stdio.h>

#define MAX 1005
#define INF 1000000000

int graph[MAX][MAX];
int visited[MAX];
int key[MAX];

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        key[i] = INF;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    int u, v, w;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        if (graph[u][v] == 0 || w < graph[u][v]) {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    key[1] = 0;

    int totalWeight = 0;

    for (int i = 1; i <= n; i++) {

        int min = INF, u = -1;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && key[j] < min) {
                min = key[j];
                u = j;
            }
        }

        visited[u] = 1;
        totalWeight += min;

        for (int vtx = 1; vtx <= n; vtx++) {
            if (graph[u][vtx] && !visited[vtx] && graph[u][vtx] < key[vtx]) {
                key[vtx] = graph[u][vtx];
            }
        }
    }

    printf("%d", totalWeight);

    return 0;
}
