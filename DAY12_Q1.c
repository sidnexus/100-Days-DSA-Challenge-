/* Problem: Write a program to check whether a given matrix is symmetric. */

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

    if(m != n)
    {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] != a[j][i])
            {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
            break;
    }

    if(flag == 1)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
