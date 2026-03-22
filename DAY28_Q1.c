// Create a circular linked list and print its elements starting from head

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i;

    scanf("%d", &n);

    struct node *head = NULL, *temp = NULL, *newnode;

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    if(temp != NULL)
    {
        temp->next = head;
    }

    temp = head;

    if(temp != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while(temp != head);
    }

    return 0;
}
