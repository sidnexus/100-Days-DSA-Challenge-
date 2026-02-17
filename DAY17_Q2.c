/*
Given an integer array nums, find the subarray with the largest sum
and print that sum.
*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[100000];
    int i;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int maxSum = a[0];
    int currentSum = a[0];

    for(i = 1; i < n; i++)
    {
        if(currentSum + a[i] > a[i])
        {
            currentSum = currentSum + a[i];
        }
        else
        {
            currentSum = a[i];
        }

        if(currentSum > maxSum)
        {
            maxSum = currentSum;
        }
    }

    printf("%d", maxSum);

    return 0;
}
