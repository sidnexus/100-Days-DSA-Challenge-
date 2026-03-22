// Evaluate postfix expression using stack implemented with linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int val)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    if(top == NULL)
        return 0;

    int val = top->data;
    struct node *temp = top;
    top = top->next;
    free(temp);

    return val;
}

int main()
{
    char ch;

    while(scanf("%c", &ch) != EOF)
    {
        if(ch == ' ' || ch == '\n')
            continue;

        if(ch >= '0' && ch <= '9')
        {
            int num = ch - '0';
            push(num);
        }
        else
        {
            int b = pop();
            int a = pop();
            int result;

            if(ch == '+')
                result = a + b;
            else if(ch == '-')
                result = a - b;
            else if(ch == '*')
                result = a * b;
            else
                result = a / b;

            push(result);
        }
    }

    printf("%d", pop());

    return 0;
}
