/* Binary Search Implementation */

#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int target;
    scanf("%d", &target);

    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans = mid;
            break;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("%d", ans);

    return 0;
}
