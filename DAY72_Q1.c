/* Find first repeated character in string (by second occurrence index) */

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};

    int resultIndex = 1000000;
    char result = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';

        freq[idx]++;

        if (freq[idx] == 2) {
            if (i < resultIndex) {
                resultIndex = i;
                result = s[i];
            }
        }
    }

    if (result == -1)
        printf("-1");
    else
        printf("%c", result);

    return 0;
}
