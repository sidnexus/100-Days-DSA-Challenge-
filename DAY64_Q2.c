/* Program to find minimum time to rot all oranges */

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int grid[100][100];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int queue[10000][2];
    int front = 0, rear = 0;

    int fresh = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
            if (grid[i][j] == 1)
                fresh++;
        }
    }

    int minutes = 0;

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while (front < rear && fresh > 0) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            int r = queue[front][0];
            int c = queue[front][1];
            front++;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    queue[rear][0] = nr;
                    queue[rear][1] = nc;
                    rear++;
                    fresh--;
                }
            }
        }

        minutes++;
    }

    if (fresh == 0)
        printf("%d", minutes);
    else
        printf("-1");

    return 0;
}
