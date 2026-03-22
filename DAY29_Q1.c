// Rotate a singly linked list to the right by k places and print the updated list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i, k;

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

    scanf("%d", &k);

    if(head == NULL || head->next == NULL)
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    int length = 1;
    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
        length++;
    }

    temp->next = head;

    k = k % length;

    int steps = length - k;

    struct node *newTail = head;

    for(i = 1; i < steps; i++)
    {
        newTail = newTail->next;
    }

    struct node *newHead = newTail->next;

    newTail->next = NULL;

    temp = newHead;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
