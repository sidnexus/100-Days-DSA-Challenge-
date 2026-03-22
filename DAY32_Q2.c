// Implement Min Stack with push, pop, top and getMin in O(1) time using two stacks

#include <stdio.h>

int main()
{
    int n, i, op, val;

    scanf("%d", &n);

    int stack[100], minStack[100];
    int top = -1, minTop = -1;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &op);

        if(op == 1)
        {
            scanf("%d", &val);

            top++;
            stack[top] = val;

            if(minTop == -1 || val <= minStack[minTop])
            {
                minTop++;
                minStack[minTop] = val;
            }
        }
        else if(op == 2)
        {
            if(top != -1)
            {
                if(stack[top] == minStack[minTop])
                {
                    minTop--;
                }
                top--;
            }
        }
        else if(op == 3)
        {
            if(top != -1)
            {
                printf("%d\n", stack[top]);
            }
        }
        else if(op == 4)
        {
            if(minTop != -1)
            {
                printf("%d\n", minStack[minTop]);
            }
        }
    }

    return 0;
}
