/* Find Redundant Connection using DSU (Union-Find) */

#include <stdio.h>

#define MAX 1005

int parent[MAX];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

int unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa == pb)
        return 0;  // cycle found

    parent[pa] = pb;
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int u, v;
    int ansU = 0, ansV = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &u, &v);

        if (!unionSet(u, v)) {
            ansU = u;
            ansV = v;
        }
    }

    printf("[%d,%d]", ansU, ansV);

    return 0;
}
