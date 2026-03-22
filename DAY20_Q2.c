// Given an integer array nums, find all unique triplets such that their sum is zero

#include <stdio.h>

int main()
{
    int n, i, j, k;

    scanf("%d", &n);

    int nums[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int found = 0;

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            for(k = j + 1; k < n; k++)
            {
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    int isDuplicate = 0;
                    int x, y, z;

                    for(x = 0; x < i; x++)
                    {
                        for(y = x + 1; y < i; y++)
                        {
                            for(z = y + 1; z < i; z++)
                            {
                                if(nums[x] + nums[y] + nums[z] == 0)
                                {
                                    if((nums[x] == nums[i] || nums[x] == nums[j] || nums[x] == nums[k]) &&
                                       (nums[y] == nums[i] || nums[y] == nums[j] || nums[y] == nums[k]) &&
                                       (nums[z] == nums[i] || nums[z] == nums[j] || nums[z] == nums[k]))
                                    {
                                        isDuplicate = 1;
                                    }
                                }
                            }
                        }
                    }

                    if(isDuplicate == 0)
                    {
                        printf("%d %d %d\n", nums[i], nums[j], nums[k]);
                        found = 1;
                    }
                }
            }
        }
    }

    if(found == 0)
    {
        printf("No triplet");
    }

    return 0;
}
