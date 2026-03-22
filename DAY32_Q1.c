// Implement push and pop operations on stack and print remaining elements from top to bottom

#include <stdio.h>

int main()
{
    int n, i, m;

    scanf("%d", &n);

    int stack[100];
    int top = -1;

    for(i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        if(top != -1)
        {
            top--;
        }
    }

    for(i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}
