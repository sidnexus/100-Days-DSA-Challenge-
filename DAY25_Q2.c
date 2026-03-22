// Find the starting node of cycle in a linked list (print its position), else print -1

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i, pos;

    scanf("%d", &n);

    struct node *head = NULL, *temp = NULL, *newnode, *cycleNode = NULL;

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

        if(i == 0)
        {
            cycleNode = head;
        }
    }

    scanf("%d", &pos);

    if(pos >= 0)
    {
        temp->next = head;
        for(i = 0; i < pos; i++)
        {
            cycleNode = cycleNode->next;
        }
        temp->next = cycleNode;
    }

    struct node *slow = head;
    struct node *fast = head;

    int hasCycle = 0;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            hasCycle = 1;
            break;
        }
    }

    if(hasCycle == 0)
    {
        printf("-1");
        return 0;
    }

    slow = head;
