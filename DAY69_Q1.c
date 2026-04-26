/* Dijkstra's Algorithm - Shortest Path using Priority Queue */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Node* createNode(int v, int w) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->vertex = v;
    n->weight = w;
    n->next = NULL;
    return n;
}

/* Min Heap (Priority Queue) */
int heapSize = 0;

struct Pair {
    int node;
    int dist;
};

struct Pair heap[MAX];

void swap(struct Pair* a, struct Pair* b) {
    struct Pair temp = *a;
    *a = *b;
    *b = temp;
}

void push(int node, int dist) {
    heap[heapSize].node = node;
    heap[heapSize].dist = dist;

    int i = heapSize++;

    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

struct Pair pop() {
    struct Pair root = heap[0];
    heap[0] = heap[--heapSize];

    int i = 0;

    while (1) {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < heapSize && heap[l].dist < heap[smallest].dist)
            smallest = l;

        if (r < heapSize && heap[r].dist < heap[smallest].dist)
            smallest = r;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v, w;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        struct Node* n1 = createNode(v, w);
        n1->next = adj[u];
        adj[u] = n1;

        struct Node* n2 = createNode(u, w);
        n2->next = adj[v];
        adj[v] = n2;
    }

    int src;
    scanf("%d", &src);

    int dist[n];

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    push(src, 0);

    while (heapSize > 0) {
        struct Pair p = pop();

        int node = p.node;
        int d = p.dist;

        if (d > dist[node])
            continue;

        struct Node* temp = adj[node];

        while (temp != NULL) {
            int vtx = temp->vertex;
            int wt = temp->weight;

            if (dist[node] + wt < dist[vtx]) {
                dist[vtx] = dist[node] + wt;
                push(vtx, dist[vtx]);
            }

            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}
