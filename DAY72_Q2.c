/* Travelling Salesman Problem using DP + Bitmask */

#include <stdio.h>
#include <limits.h>

#define MAX 15
#define INF 1000000000

int n;
int cost[MAX][MAX];
int dp[MAX][1 << MAX];

int tsp(int pos, int mask) {

    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }

    if (dp[pos][mask] != -1)
        return dp[pos][mask];

    int ans = INF;

    for (int city = 0; city < n; city++) {

        if ((mask & (1 << city)) == 0) {

            int newCost = cost[pos][city] + tsp(city, mask | (1 << city));

            if (newCost < ans)
                ans = newCost;
        }
    }

    return dp[pos][mask] = ans;
}

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < (1 << MAX); j++) {
            dp[i][j] = -1;
        }
    }

    int result = tsp(0, 1);

    printf("%d", result);

    return 0;
}
