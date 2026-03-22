// Implement stack using array with push, pop and display operations

#include <stdio.h>

int main()
{
    int n, i, op, value;

    scanf("%d", &n);

    int stack[100];
    int top = -1;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &op);

        if(op == 1)
        {
            scanf("%d", &value);
            top++;
            stack[top] = value;
        }
        else if(op == 2)
        {
            if(top == -1)
            {
                printf("Stack Underflow\n");
            }
            else
            {
                printf("%d\n", stack[top]);
                top--;
            }
        }
        else if(op == 3)
        {
            int j;

            for(j = top; j >= 0; j--)
            {
                printf("%d ", stack[j]);
            }
            printf("\n");
        }
    }

    return 0;
}
