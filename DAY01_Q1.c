/* Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space. */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n + 1];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos, x;
    scanf("%d", &pos);
    scanf("%d", &x);

    int index = pos - 1;

    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = x;

    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
