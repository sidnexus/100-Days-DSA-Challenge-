/* Program to perform flood fill on a 2D grid */

#include <stdio.h>

int m, n;

void dfs(int image[100][100], int r, int c, int oldColor, int newColor) {
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    if (image[r][c] != oldColor)
        return;

    image[r][c] = newColor;

    dfs(image, r + 1, c, oldColor, newColor);
    dfs(image, r - 1, c, oldColor, newColor);
    dfs(image, r, c + 1, oldColor, newColor);
    dfs(image, r, c - 1, oldColor, newColor);
}

int main() {
    scanf("%d %d", &m, &n);

    int image[100][100];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    int sr, sc, color;
    scanf("%d %d %d", &sr, &sc, &color);

    int oldColor = image[sr][sc];

    if (oldColor != color) {
        dfs(image, sr, sc, oldColor, color);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
