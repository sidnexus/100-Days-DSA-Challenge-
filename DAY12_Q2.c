/* Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false. */

#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int a[m][n];
    int i, j;
    int flag = 1;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 1; i < m; i++)
    {
        for(j = 1; j < n; j++)
        {
            if(a[i][j] != a[i - 1][j - 1])
            {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
            break;
    }

    if(flag == 1)
        printf("true");
    else
        printf("false");

    return 0;
}
