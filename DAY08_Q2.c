/* Given an integer n, return true if it is a power of two. Otherwise, return false. */

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("false");
        return 0;
    }

    while(n % 2 == 0)
    {
        n = n / 2;
    }

    if(n == 1)
        printf("true");
    else
        printf("false");

    return 0;
}
