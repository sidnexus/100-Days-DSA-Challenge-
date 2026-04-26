/* Alien Dictionary - Topological Sort using Kahn's Algorithm */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET 26

struct Node {
    int v;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->v = v;
    n->next = NULL;
    return n;
}

int main() {
    int n;
    scanf("%d", &n);

    char words[500][101];

    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    struct Node* adj[ALPHABET];
    int indegree[ALPHABET] = {0};
    int present[ALPHABET] = {0};

    for (int i = 0; i < ALPHABET; i++)
        adj[i] = NULL;

    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j] != '\0'; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];

        int len1 = strlen(w1);
        int len2 = strlen(w2);

        int found = 0;

        for (int j = 0; j < len1 && j < len2; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';

                struct Node* newNode = createNode(v);
                newNode->next = adj[u];
                adj[u] = newNode;

                indegree[v]++;
                found = 1;
                break;
            }
        }

        if (!found && len1 > len2) {
            printf("");
            return 0;
        }
    }

    int queue[26], front = 0, rear = 0;

    for (int i = 0; i < ALPHABET; i++) {
        if (present[i] && indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    char result[27];
    int idx = 0;

    while (front < rear) {
        int node = queue[front++];
        result[idx++] = node + 'a';

        struct Node* temp = adj[node];

        while (temp != NULL) {
            indegree[temp->v]--;

            if (indegree[temp->v] == 0)
                queue[rear++] = temp->v;

            temp = temp->next;
        }
    }

    int total = 0;
    for (int i = 0; i < ALPHABET; i++) {
        if (present[i]) total++;
    }

    if (idx != total) {
        printf("");
    } else {
        result[idx] = '\0';
        printf("%s", result);
    }

    return 0;
}
