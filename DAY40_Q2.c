#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int temps[n], ans[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &temps[i]);
    int stack[n], top = -1;
    for(int i = n-1; i >= 0; i--) {
        while(top != -1 && temps[i] >= temps[stack[top]])
            top--;
        ans[i] = (top == -1) ? 0 : stack[top] - i;
        stack[++top] = i;
    }
    for(int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    return 0;
}
