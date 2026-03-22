#include <stdio.h>
#include <ctype.h>

int main()
{
    char s[300010]; // input string large enough for constraint
    fgets(s, sizeof(s), stdin);

    int stack[300010];
    int top = -1;

    int num = 0;
    char sign = '+';

    for(int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];

        if(isdigit(ch))
        {
            num = num * 10 + (ch - '0');
        }

        // If operator or end of string
        if((!isdigit(ch) && ch != ' ') || s[i+1] == '\0')
        {
            if(sign == '+')
            {
                stack[++top] = num;
            }
            else if(sign == '-')
            {
                stack[++top] = -num;
            }
            else if(sign == '*')
            {
                int temp = stack[top--];
                stack[++top] = temp * num;
            }
            else if(sign == '/')
            {
                int temp = stack[top--];
                stack[++top] = temp / num; // integer division truncates toward zero
            }

            sign = ch;
            num = 0;
        }
    }

    int result = 0;
    for(int i = 0; i <= top; i++)
    {
        result += stack[i];
    }

    printf("%d", result);
    return 0;
}
