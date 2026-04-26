/* Check if Graph is Bipartite using BFS Coloring */

#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int size[MAX];
int color[MAX];

int queue[MAX];
int front, rear;

int bfs(int start, int n) {

    queue[rear++] = start;
    color[start] = 1;

    while (front < rear) {
        int node = queue[front++];

        for (int i = 0; i < size[node]; i++) {
            int v = graph[node][i];

            if (color[v] == -1) {
                color[v] = 1 - color[node];
                queue[rear++] = v;
            }
            else if (color[v] == color[node]) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        size[i] = 0;
        color[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int u;
        while (1) {
            scanf("%d", &u);
            if (u == -1) break;
            graph[i][size[i]++] = u;
        }
    }

    int result = 1;

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            front = rear = 0;
            if (!bfs(i, n)) {
                result = 0;
                break;
            }
        }
    }

    if (result)
        printf("true");
    else
        printf("false");

    return 0;
}
