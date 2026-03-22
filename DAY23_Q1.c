// Merge two sorted singly linked lists and print the merged list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

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

    struct node *head3 = NULL, *temp3 = NULL;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data)
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = head1->data;
            newnode->next = NULL;
            head1 = head1->next;
        }
        else
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = head2->data;
            newnode->next = NULL;
            head2 = head2->next;
        }

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

    while(head1 != NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = head1->data;
        newnode->next = NULL;

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

        head1 = head1->next;
    }

    while(head2 != NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = head2->data;
        newnode->next = NULL;

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

        head2 = head2->next;
    }

    temp3 = head3;

    while(temp3 != NULL)
    {
        printf("%d ", temp3->data);
        temp3 = temp3->next;
    }

    return 0;
}
