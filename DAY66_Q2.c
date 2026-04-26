/* Program to check if all courses can be finished (Cycle detection in directed graph) */

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

int visited[2000];
int recStack[2000];

int dfs(int node, struct Node* adj[]) {
    visited[node] = 1;
    recStack[node] = 1;

    struct Node* temp = adj[node];

    while (temp != NULL) {
        int v = temp->vertex;

        if (!visited[v]) {
            if (dfs(v, adj))
                return 1;
        }
        else if (recStack[v]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[node] = 0;
    return 0;
}

int main() {
    int numCourses, m;

    scanf("%d", &numCourses);
    scanf("%d", &m);

    struct Node* adj[numCourses];

    for (int i = 0; i < numCourses; i++)
        adj[i] = NULL;

    int a, b;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);

        struct Node* newNode = createNode(a);
        newNode->next = adj[b];
        adj[b] = newNode;
    }

    for (int i = 0; i < numCourses; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    int cycle = 0;

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, adj)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("false");
    else
        printf("true");

    return 0;
}
