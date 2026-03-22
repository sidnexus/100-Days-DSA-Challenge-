// Remove all nodes from linked list whose value is equal to given val and print the updated list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i, val;

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

    scanf("%d", &val);

    while(head != NULL && head->data == val)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    struct node *curr = head;

    while(curr != NULL && curr->next != NULL)
    {
        if(curr->next->data == val)
        {
            temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
        else
        {
            curr = curr->next;
        }
    }

    temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
