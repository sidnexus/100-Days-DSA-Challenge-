// Add two numbers represented by linked lists (digits in forward order) and print the result list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *next = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main()
{
    int n, m, i;

    scanf("%d", &n);

    struct node *head1 = NULL, *temp1 = NULL, *newnode;

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head1 == NULL)
        {
            head1 = newnode;
            temp1 = newnode;
        }
        else
        {
            temp1->next = newnode;
            temp1 = newnode;
        }
    }

    scanf("%d", &m);

    struct node *head2 = NULL, *temp2 = NULL;

    for(i = 0; i < m; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head2 == NULL)
        {
            head2 = newnode;
            temp2 = newnode;
        }
        else
        {
            temp2->next = newnode;
            temp2 = newnode;
        }
    }

    head1 = reverse(head1);
    head2 = reverse(head2);

    struct node *head3 = NULL, *temp3 = NULL;

    int carry = 0;

    while(head1 != NULL || head2 != NULL || carry != 0)
    {
        int sum = carry;

        if(head1 != NULL)
        {
            sum = sum + head1->data;
            head1 = head1->next;
        }

        if(head2 != NULL)
        {
            sum = sum + head2->data;
            head2 = head2->next;
        }

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = sum % 10;
        newnode->next = NULL;

        carry = sum / 10;

        if(head3 == NULL)
        {
            head3 = newnode;
            temp3 = newnode;
        }
        else
        {
            temp3->next = newnode;
            temp3 = newnode;
        }
    }

    head3 = reverse(head3);

    temp3 = head3;

    while(temp3 != NULL)
    {
        printf("%d ", temp3->data);
        temp3 = temp3->next;
    }

    return 0;
}
