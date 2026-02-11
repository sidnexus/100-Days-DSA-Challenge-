/* Write a function that reverses a string given as a character array by modifying the array in-place using O(1) extra memory. */

#include <stdio.h>
#include <string.h>

void reverse(char s[], int n)
{
    int start = 0;
    int end = n - 1;

    while(start < end)
    {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    char s[100];
    scanf("%s", s);

    int n = strlen(s);

    reverse(s, n);

    printf("%s", s);

    return 0;
}
