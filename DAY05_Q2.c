/* Merge two sorted arrays nums1 and nums2 into nums1 in non-decreasing order where nums1 has size m+n with last n elements empty. */

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d", &m);

    int nums1[m + n];
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    scanf("%d", &n);

    int nums2[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    int i = m - 1, j = n - 1, k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    for (int x = 0; x < m + n; x++) {
        printf("%d ", nums1[x]);
    }

    return 0;
}
