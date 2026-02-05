/* Given an array of size n-1 containing distinct integers from 1 to n with one number missing, find the missing number. */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n - 1];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = n * (n + 1) / 2;
    int arrSum = 0;

    for (int i = 0; i < n - 1; i++) {
        arrSum += arr[i];
    }

    printf("%d", sum - arrSum);

    return 0;
}
