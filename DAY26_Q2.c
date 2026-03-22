// Implement a singly linked list with operations: get, addAtHead, addAtTail, addAtIndex, deleteAtIndex

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct node *head = NULL;

int get(int index)
{
    struct node *temp = head;
    int i = 0;

    while(temp != NULL)
    {
        if(i == index)
            return temp->val;

        temp = temp->next;
        i++;
    }

    return -1;
}

void addAtHead(int val)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->val = val;
    newnode->next = head;
    head = newnode;
}

void addAtTail(int val)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->val = val;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        return;
    }

    struct node *temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}

void addAtIndex(int index, int val)
{
    if(index == 0)
    {
        addAtHead(val);
        return;
    }

    struct node *temp = head;
    int i = 0;

    while(temp != NULL && i < index - 1)
    {
        temp = temp->next;
        i++;
    }

    if(temp == NULL)
        return;

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->val = val;
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteAtIndex(int index)
{
    if(head == NULL)
        return;

    if(index == 0)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct node *temp = head;
    int i = 0;

    while(temp->next != NULL && i < index - 1)
    {
        temp = temp->next;
        i++;
    }

    if(temp->next == NULL)
        return;

    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
}

int main()
{
    addAtHead(1);
    addAtTail(3);
    addAtIndex(1, 2);

    printf("%d\n", get(1));

    deleteAtIndex(1);

    printf("%d\n", get(1));

    return 0;
}
