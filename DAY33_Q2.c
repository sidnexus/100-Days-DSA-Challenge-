// Evaluate Reverse Polish Notation (Postfix Expression) using stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i;

    scanf("%d", &n);

    char tokens[n][20];

    for(i = 0; i < n; i++)
    {
        scanf("%s", tokens[i]);
    }

    int stack[1000];
    int top = -1;

    for(i = 0; i < n; i++)
    {
        if(strcmp(tokens[i], "+") == 0 ||
           strcmp(tokens[i], "-") == 0 ||
           strcmp(tokens[i], "*") == 0 ||
           strcmp(tokens[i], "/") == 0)
        {
            int b = stack[top--];
            int a = stack[top--];
            int result;

            if(strcmp(tokens[i], "+") == 0)
                result = a + b;
            else if(strcmp(tokens[i], "-") == 0)
                result = a - b;
            else if(strcmp(tokens[i], "*") == 0)
                result = a * b;
            else
                result = a / b;

            stack[++top] = result;
        }
        else
        {
            int num = atoi(tokens[i]);
            stack[++top] = num;
        }
    }

    printf("%d", stack[top]);

    return 0;
}
