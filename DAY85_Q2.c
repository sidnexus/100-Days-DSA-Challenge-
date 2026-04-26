/* Find Minimum in Rotated Sorted Array */

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

        // If mid is greater than high, minimum is in right half
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        }
        // else minimum is in left half (including mid)
        else {
            high = mid;
        }
    }

    printf("%d", nums[low]);

    return 0;
}
