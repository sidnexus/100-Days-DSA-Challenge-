// Given an array of integers, rotate the array to the right by k positions

#include <stdio.h>

int main()
{
    int n, k, i;

    scanf("%d", &n);

    int arr[n], temp[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    k = k % n;

    for(i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }

    for(i = 0; i < n; i++)
    {
        printf("%d ", temp[i]);
    }

    return 0;
}
