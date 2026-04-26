/* Longest Subarray with Sum = 0 */

#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefixSum = 0;

    int hash[200000];
    for (int i = 0; i < 200000; i++)
        hash[i] = -2;

    int offset = 100000;

    int maxLen = 0;

    for (int i = 0; i < n; i++) {

        prefixSum += arr[i];

        if (prefixSum == 0) {
            if (i + 1 > maxLen)
                maxLen = i + 1;
        }

        if (hash[prefixSum + offset] != -2) {
            int len = i - hash[prefixSum + offset];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[prefixSum + offset] = i;
        }
    }

    printf("%d", maxLen);

    return 0;
}
