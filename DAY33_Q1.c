// Convert an infix expression to postfix using stack

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[100];
    scanf("%s", infix);

    char stack[100];
    int top = -1;

    char postfix[100];
    int k = 0;

    int i;

    for(i = 0; i < strlen(infix); i++)
    {
        char ch = infix[i];

        if(isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if(ch == '(')
        {
            top++;
            stack[top] = ch;
        }
        else if(ch == ')')
        {
            while(top != -1 && stack[top] != '(')
            {
                postfix[k++] = stack[top];
                top--;
            }
            if(top != -1)
                top--;
        }
        else
        {
            while(top != -1 && precedence(stack[top]) >= precedence(ch))
            {
                postfix[k++] = stack[top];
                top--;
            }
            top++;
            stack[top] = ch;
        }
    }

    while(top != -1)
    {
        postfix[k++] = stack[top];
        top--;
    }

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}
