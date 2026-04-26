/* Program to build graph using adjacency list (linked list) */

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

    int type;
    scanf("%d", &type);   // 0 = undirected, 1 = directed

    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        if (type == 0) {
            struct Node* newNode2 = createNode(u);
            newNode2->next = adj[v];
            adj[v] = newNode2;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];

        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}
