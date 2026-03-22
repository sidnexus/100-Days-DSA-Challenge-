#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);
    int pq[1000];
    int size = 0;
    char op[20];

    for(int i = 0; i < N; i++)
    {
        scanf("%s", op);
        if(strcmp(op, "insert") == 0)
        {
            int x;
            scanf("%d", &x);
            pq[size++] = x;
        }
        else if(strcmp(op, "delete") == 0)
        {
            if(size == 0)
            {
                printf("-1\n");
            }
            else
            {
                int minIndex = 0;
                for(int j = 1; j < size; j++)
                    if(pq[j] < pq[minIndex])
                        minIndex = j;
                printf("%d\n", pq[minIndex]);
                for(int j = minIndex; j < size - 1; j++)
                    pq[j] = pq[j + 1];
                size--;
            }
        }
        else if(strcmp(op, "peek") == 0)
        {
            if(size == 0)
            {
                printf("-1\n");
            }
            else
            {
                int minIndex = 0;
                for(int j = 1; j < size; j++)
                    if(pq[j] < pq[minIndex])
                        minIndex = j;
                printf("%d\n", pq[minIndex]);
            }
        }
    }

    return 0;
}
