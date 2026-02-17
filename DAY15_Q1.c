/*
Problem: Given a matrix, calculate the sum of its primary diagonal elements.
The primary diagonal consists of elements where row index equals column index.
*/

#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int a[100][100];
    int i, j;
    int sum = 0;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int limit;

    if(m < n)
        limit = m;
    else
        limit = n;

    for(i = 0; i < limit; i++)
    {
        sum = sum + a[i][i];
    }

    printf("%d", sum);

    return 0;
}
