/* BFS Traversal using Queue */

#include <stdio.h>

#define MAX 1005

int adj[MAX][10];
int size[MAX];

int visited[MAX];
int queue[MAX];

int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {

    int n;
    scanf("%d", &n);

    // adjacency list input
    for (int i = 0; i < n; i++) {
        scanf("%d", &size[i]);
        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int s;
    scanf("%d", &s);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // BFS start
    visited[s] = 1;
    enqueue(s);

    while (!isEmpty()) {

        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < size[node]; i++) {

            int v = adj[node][i];

            if (!visited[v]) {
                visited[v] = 1;
                enqueue(v);
            }
        }
    }

    return 0;
}
