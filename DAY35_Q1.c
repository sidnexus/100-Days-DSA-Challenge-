// Implement a queue using array and display elements from front to rear

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    scanf("%d", &n);

    int queue[1000];
    int front = 0, rear = -1;

    for(i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        rear++;
        queue[rear] = val; // enqueue
    }

    // Display queue from front to rear
    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}
