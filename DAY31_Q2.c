// Check if given string of brackets is valid using stack

#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    scanf("%s", s);

    char stack[100];
    int top = -1;

    int i;

    for(i = 0; i < strlen(s); i++)
    {
        char ch = s[i];

        if(ch == '(' || ch == '{' || ch == '[')
        {
            top++;
            stack[top] = ch;
        }
        else
        {
            if(top == -1)
            {
                printf("false");
                return 0;
            }

            char topChar = stack[top];
            top--;

            if((ch == ')' && topChar != '(') ||
               (ch == '}' && topChar != '{') ||
               (ch == ']' && topChar != '['))
            {
                printf("false");
                return 0;
            }
        }
    }

    if(top == -1)
        printf("true");
    else
        printf("false");

    return 0;
}
