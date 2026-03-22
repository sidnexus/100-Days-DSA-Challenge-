#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

int stack1[MAX], top1 = -1;
int stack2[MAX], top2 = -1;

void push(int x)
{
    stack1[++top1] = x;
}

void transfer()
{
    if(top2 == -1)
    {
        while(top1 != -1)
        {
            stack2[++top2] = stack1[top1--];
        }
    }
}

int pop()
{
    transfer();
    if(top2 != -1)
        return stack2[top2--];
    return -1;
}

int peek()
{
    transfer();
    if(top2 != -1)
        return stack2[top2];
    return -1;
}

bool empty()
{
    return (top1 == -1 && top2 == -1);
}

int main()
{
    push(1);
    push(2);
    printf("%d\n", peek());
    printf("%d\n", pop());
    printf("%s\n", empty() ? "true" : "false");

    return 0;
}
