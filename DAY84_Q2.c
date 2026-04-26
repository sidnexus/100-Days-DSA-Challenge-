/* Find Peak Element using Binary Search */

#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int nums[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int low = 0, high = n - 1;

    while (low < high) {

        int mid = low + (high - low) / 2;

        // If mid is less than next element, peak is on right side
        if (nums[mid] < nums[mid + 1]) {
            low = mid + 1;
        }
        // else peak is on left side (including mid)
        else {
            high = mid;
        }
    }

    printf("%d", low);

    return 0;
}
