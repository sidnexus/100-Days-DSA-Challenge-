// Given an integer array nums, return an array such that each element is product of all elements except itself without using division

#include <stdio.h>

int main()
{
    int n, i;

    scanf("%d", &n);

    int nums[n], answer[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int left[n], right[n];

    left[0] = 1;
    for(i = 1; i < n; i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }

    right[n - 1] = 1;
    for(i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i + 1];
    }

    for(i = 0; i < n; i++)
    {
        answer[i] = left[i] * right[i];
    }

    for(i = 0; i < n; i++)
    {
        printf("%d ", answer[i]);
    }

    return 0;
}
