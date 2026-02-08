/* The Fibonacci numbers, commonly denoted F(n), form a sequence where F(0)=0, F(1)=1 and F(n)=F(n-1)+F(n-2) for n>1. Given n, calculate F(n). */

#include <stdio.h>

int fib(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    scanf("%d", &n);

    int ans = fib(n);

    printf("%d", ans);

    return 0;
}
