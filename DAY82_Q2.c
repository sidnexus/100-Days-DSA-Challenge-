/* Search Insert Position using Binary Search */

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
    int ans = n;  // default insert at end

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}
