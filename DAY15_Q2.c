/*
Given an m x n integer matrix, if an element is 0,
set its entire row and column to 0's.
You must do it in place.
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

    int firstRowZero = 0;
    int firstColZero = 0;

    for(i = 0; i < m; i++)
    {
        if(a[i][0] == 0)
        {
            firstColZero = 1;
        }
    }

    for(j = 0; j < n; j++)
    {
        if(a[0][j] == 0)
        {
            firstRowZero = 1;
        }
    }

    for(i = 1; i < m; i++)
    {
        for(j = 1; j < n; j++)
        {
            if(a[i][j] == 0)
            {
                a[i][0] = 0;
                a[0][j] = 0;
            }
        }
    }

    for(i = 1; i < m; i++)
    {
        for(j = 1; j < n; j++)
        {
            if(a[i][0] == 0 || a[0][j] == 0)
            {
                a[i][j] = 0;
            }
        }
    }

    if(firstRowZero == 1)
    {
        for(j = 0; j < n; j++)
        {
            a[0][j] = 0;
        }
    }

    if(firstColZero == 1)
    {
        for(i = 0; i < m; i++)
        {
            a[i][0] = 0;
        }
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
