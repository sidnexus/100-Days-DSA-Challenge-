#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d", &n);
    int nums[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    scanf("%d", &k);

    int deque[n];
    int front = 0, rear = -1;
    int res[n], ri = 0;

    for(int i = 0; i < n; i++) {
        while(front <= rear && deque[front] <= i - k)
            front++;
        while(front <= rear && nums[deque[rear]] < nums[i])
            rear--;
        deque[++rear] = i;
        if(i >= k - 1)
            res[ri++] = nums[deque[front]];
    }

    for(int i = 0; i < ri; i++)
        printf("%d ", res[i]);

    return 0;
}
