/* Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays. */

#include <stdio.h>

int main()
{
    int n1, n2;
    scanf("%d", &n1);

    int a[n1];
    int i, j;

    for(i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &n2);
    int b[n2];

    for(i = 0; i < n2; i++)
    {
        scanf("%d", &b[i]);
    }

    for(i = 0; i < n1; i++)
    {
        for(j = 0; j < n2; j++)
        {
            if(a[i] == b[j])
            {
                printf("%d ", a[i]);
                b[j] = -1;
                break;
            }
        }
    }

    return 0;
}
