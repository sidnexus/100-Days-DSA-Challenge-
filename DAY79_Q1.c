/* Dijkstra's Algorithm for Shortest Path */

#include <stdio.h>

#define MAX 1005
#define INF 1000000000

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;

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

    int source;
    scanf("%d", &source);

    dist[source] = 0;

    for (int i = 1; i <= n; i++) {

        int min = INF, u = -1;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int vtx = 1; vtx <= n; vtx++) {
            if (graph[u][vtx] != 0 && !visited[vtx]) {

                if (dist[u] + graph[u][vtx] < dist[vtx]) {
                    dist[vtx] = dist[u] + graph[u][vtx];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    return 0;
}
