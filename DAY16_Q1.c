/*
Problem: Given an array of integers, count the frequency of each distinct element
and print the result in the format element:count
*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[100];
    int i, j;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int visited[100] = {0};

    for(i = 0; i < n; i++)
    {
        if(visited[i] == 1)
            continue;

        int count = 1;

        for(j = i + 1; j < n; j++)
        {
            if(a[i] == a[j])
            {
                count++;
                visited[j] = 1;
            }
        }

        printf("%d:%d ", a[i], count);
    }

    return 0;
}
