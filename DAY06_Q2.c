/* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements. */

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    int i;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int pos = 0;

    for(i = 0; i < n; i++)
    {
        if(arr[i] != 0)
        {
            arr[pos] = arr[i];
            pos++;
        }
    }

    while(pos < n)
    {
        arr[pos] = 0;
        pos++;
    }

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
