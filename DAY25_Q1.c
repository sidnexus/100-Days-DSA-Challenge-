// Count occurrences of a given key in a singly linked list and print the count

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i, key;

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

    scanf("%d", &key);

    int count = 0;
    temp = head;

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            count++;
        }
        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}
