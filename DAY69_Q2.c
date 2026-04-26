/* Network Delay Time using Dijkstra (Min Priority Queue) */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10000

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

/* Min Heap */
struct Pair {
    int node;
    int dist;
};

struct Pair heap[MAX];
int heapSize = 0;

void swap(struct Pair* a, struct Pair* b) {
    struct Pair t = *a;
    *a = *b;
    *b = t;
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
    int m, n, k;

    scanf("%d %d %d", &m, &n, &k);

    struct Node* adj[n + 1];

    for (int i = 0; i <= n; i++)
        adj[i] = NULL;

    int u, v, w;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        struct Node* newNode = createNode(v, w);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int dist[n + 1];

    for (int i = 0; i <= n; i++)
        dist[i] = INT_MAX;

    dist[k] = 0;
    push(k, 0);

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

    int maxTime = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            printf("-1");
            return 0;
        }
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }

    printf("%d", maxTime);

    return 0;
}
