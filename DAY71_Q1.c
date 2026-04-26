/* Hash Table using Quadratic Probing */

#include <stdio.h>

#define SIZE 7
#define EMPTY -1

int table[SIZE];

int hashFunc(int key) {
    return key % SIZE;
}

void insert(int key) {
    int h = hashFunc(key);

    for (int i = 0; i < SIZE; i++) {
        int idx = (h + i * i) % SIZE;

        if (table[idx] == EMPTY || table[idx] == -2) {
            table[idx] = key;
            return;
        }
    }
}

int search(int key) {
    int h = hashFunc(key);

    for (int i = 0; i < SIZE; i++) {
        int idx = (h + i * i) % SIZE;

        if (table[idx] == EMPTY)
            return 0;

        if (table[idx] == key)
            return 1;
    }

    return 0;
}

int main() {
    int n, q;

    scanf("%d", &n);
    scanf("%d", &q);

    for (int i = 0; i < SIZE; i++)
        table[i] = EMPTY;

    char op[10];
    int key;

    for (int i = 0; i < n + q; i++) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {
            insert(key);
        }
        else if (op[0] == 'S') {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
