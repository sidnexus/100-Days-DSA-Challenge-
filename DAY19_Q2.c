// Given a circular integer array, find the maximum possible sum of a non-empty subarray

#include <stdio.h>

int main()
{
    int n, i;

    scanf("%d", &n);

    int nums[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int maxSum = nums[0], currMax = nums[0];
    int minSum = nums[0], currMin = nums[0];
    int total = nums[0];

    for(i = 1; i < n; i++)
    {
        if(currMax + nums[i] > nums[i])
            currMax = currMax + nums[i];
        else
            currMax = nums[i];

        if(currMax > maxSum)
            maxSum = currMax;

        if(currMin + nums[i] < nums[i])
            currMin = currMin + nums[i];
        else
            currMin = nums[i];

        if(currMin < minSum)
            minSum = currMin;

        total = total + nums[i];
    }

    int result;

    if(total == minSum)
        result = maxSum;
    else
    {
        if(maxSum > (total - minSum))
            result = maxSum;
        else
            result = total - minSum;
    }

    printf("%d", result);

    return 0;
}
