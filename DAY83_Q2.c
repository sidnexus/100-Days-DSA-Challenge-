/* Search in Rotated Sorted Array */

#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int nums[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int target;
    scanf("%d", &target);

    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            ans = mid;
            break;
        }

        // Left half is sorted
        if (nums[low] <= nums[mid]) {

            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Right half is sorted
        else {

            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    printf("%d", ans);

    return 0;
}
