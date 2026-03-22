// Find intersection point of two linked lists and print the value or "No Intersection"

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

    int len1 = 0, len2 = 0;
    temp1 = head1;
    temp2 = head2;

    while(temp1 != NULL)
    {
        len1++;
        temp1 = temp1->next;
    }

    while(temp2 != NULL)
    {
        len2++;
        temp2 = temp2->next;
    }

    temp1 = head1;
    temp2 = head2;

    int diff;

    if(len1 > len2)
    {
        diff = len1 - len2;
        for(i = 0; i < diff; i++)
        {
            temp1 = temp1->next;
        }
    }
    else
    {
        diff = len2 - len1;
        for(i = 0; i < diff; i++)
        {
            temp2 = temp2->next;
        }
    }

    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->data == temp2->data)
        {
            printf("%d", temp1->data);
            return 0;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    printf("No Intersection");

    return 0;
}
