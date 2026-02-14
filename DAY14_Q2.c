/*
You are given an n x n 2D matrix representing an image,
rotate the image by 90 degrees clockwise in-place.
Do not use another 2D matrix.
*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[100][100];
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    for(i = 0; i < n; i++)
    {
        int start = 0;
        int end = n - 1;

        while(start < end)
        {
            int temp = a[i][start];
            a[i][start] = a[i][end];
            a[i][end] = temp;

            start++;
            end--;
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
