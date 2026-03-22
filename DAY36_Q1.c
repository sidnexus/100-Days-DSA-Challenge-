#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, m;
    scanf("%d", &n);

    int queue[1000];
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    scanf("%d", &m);

    int front = 0;
    int rear = n - 1;
    int size = n;

    for(i = 0; i < m; i++)
    {
        front = (front + 1) % n;
        size--;
    }

    for(i = 0; i < size; i++)
    {
        printf("%d ", queue[(front + i) % n]);
    }

    return 0;
}
