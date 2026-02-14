/*
Given an m x n matrix, return all elements of the matrix in spiral order.
*/

#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int a[100][100];
    int i, j;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;

    while(top <= bottom && left <= right)
    {
        for(i = left; i <= right; i++)
        {
            printf("%d ", a[top][i]);
        }
        top++;

        for(i = top; i <= bottom; i++)
        {
            printf("%d ", a[i][right]);
        }
        right--;

        if(top <= bottom)
        {
            for(i = right; i >= left; i--)
            {
                printf("%d ", a[bottom][i]);
            }
            bottom--;
        }

        if(left <= right)
        {
            for(i = bottom; i >= top; i--)
            {
                printf("%d ", a[i][left]);
            }
            left++;
        }
    }

    return 0;
}
