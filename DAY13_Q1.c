/*
Problem: You are given a rectangular matrix of integers.
Traverse the matrix in clockwise spiral order and print all elements.
*/

#include <stdio.h>

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);

    int a[100][100];
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int top = 0;
    int bottom = r - 1;
    int left = 0;
    int right = c - 1;

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
