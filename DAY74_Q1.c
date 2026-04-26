/* Find winner with maximum votes (lexicographically smallest in tie) */

#include <stdio.h>
#include <string.h>

#define MAX 1000

char names[MAX][100];
int freq[MAX];
int size = 0;

int findIndex(char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(names[i], name) == 0)
            return i;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    char name[100];

    for (int i = 0; i < n; i++) {
        scanf("%s", name);

        int idx = findIndex(name);

        if (idx == -1) {
            strcpy(names[size], name);
            freq[size] = 1;
            size++;
        } else {
            freq[idx]++;
        }
    }

    int maxVotes = 0;
    char winner[100] = "";

    for (int i = 0; i < size; i++) {

        if (freq[i] > maxVotes) {
            maxVotes = freq[i];
            strcpy(winner, names[i]);
        }
        else if (freq[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}
