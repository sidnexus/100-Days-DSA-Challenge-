#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d",&N);
    int queue[N], stack[N];
    int top=-1;
    for(int i=0;i<N;i++){
        scanf("%d",&queue[i]);
        stack[++top]=queue[i];
    }
    for(int i=0;i<N;i++){
        printf("%d ",stack[top--]);
    }
    return 0;
}
