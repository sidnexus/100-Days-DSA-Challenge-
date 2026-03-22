// Check if a singly linked list is palindrome and print true or false

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

    int arr[n];
    int index = 0;

    temp = head;

    while(temp != NULL)
    {
        arr[index] = temp->data;
        index++;
        temp = temp->next;
    }

    int start = 0;
    int end = n - 1;
    int isPalindrome = 1;

    while(start < end)
    {
        if(arr[start] != arr[end])
        {
            isPalindrome = 0;
            break;
        }
        start++;
        end--;
    }

    if(isPalindrome == 1)
        printf("true");
    else
        printf("false");

    return 0;
}
