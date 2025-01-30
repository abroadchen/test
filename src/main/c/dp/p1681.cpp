#include <algorithm>
#include <cstdio>
using namespace std;

#define MAX_N 1500
int dp[MAX_N + 5][MAX_N + 5][2];

int main (int argc, char *argv[]) {
    int n, m, ans;
    scanf("%d%d", &n, &m);
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        for (int j = 1; j <= m; j++) {
            dp[i][j][1 - a] = 0;
            dp[i][j][a] = min(
                dp[i - 1][j - 1][a], min(
                    dp[i - 1][j][1 - a],
                    dp[i][j - 1][1 - a]
                )
            ) + 1;
            ans = max(ans, dp[i][j][a]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
