/* Program to find course order using Kahn's Algorithm (Topological Sort BFS) */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->vertex = v;
    n->next = NULL;
    return n;
}

int main() {
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int indegree[n];
    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;

        indegree[u]++;
    }

    int queue[n];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int result[n];
    int idx = 0;

    while (front < rear) {
        int node = queue[front++];
        result[idx++] = node;

        struct Node* temp = adj[node];

        while (temp != NULL) {
            int vtx = temp->vertex;
            indegree[vtx]--;

            if (indegree[vtx] == 0)
                queue[rear++] = vtx;

            temp = temp->next;
        }
    }

    if (idx != n) {
        printf("[]");
    } else {
        for (int i = 0; i < idx; i++) {
            printf("%d ", result[i]);
        }
    }

    return 0;
}
