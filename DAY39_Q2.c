#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    scanf("%d", &n);
    int nums[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    scanf("%d", &k);

    int offset = 10000;
    int freq[20001] = {0};
    for(int i = 0; i < n; i++)
        freq[nums[i] + offset]++;

    int buckets[n+1];
    for(int i = 0; i <= n; i++)
        buckets[i] = 0;

    int count_map[20001];
    int unique = 0;
    for(int i = 0; i <= 20000; i++)
        if(freq[i] > 0)
            count_map[unique++] = i;

    int res[k], ri = 0;
    for(int f = n; f >= 1 && ri < k; f--)
        for(int i = 0; i < unique && ri < k; i++)
            if(freq[count_map[i]] == f)
                res[ri++] = count_map[i] - offset;

    for(int i = 0; i < k; i++)
        printf("%d ", res[i]);

    return 0;
}
