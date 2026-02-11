/* Problem: A secret system stores code names in forward order. To display them in mirror format, transform the string so characters appear in reverse order. */

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    scanf("%s", str);

    int len = strlen(str);
    int i;

    for(i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }

    return 0;
}
