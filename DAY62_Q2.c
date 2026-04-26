/* Program to check if all rooms can be visited */

#include <stdio.h>

int n;
int visited[1000];

void dfs(int room, int rooms[1000][1000], int size[]) {
    visited[room] = 1;

    for (int i = 0; i < size[room]; i++) {
        int next = rooms[room][i];

        if (!visited[next]) {
            dfs(next, rooms, size);
        }
    }
}

int main() {
    scanf("%d", &n);

    int rooms[1000][1000];
    int size[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &size[i]);

        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(0, rooms, size);

    int allVisited = 1;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            allVisited = 0;
            break;
        }
    }

    if (allVisited)
        printf("true");
    else
        printf("false");

    return 0;
}
