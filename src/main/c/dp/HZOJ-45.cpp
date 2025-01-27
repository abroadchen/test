#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 1000
char s1[MAX_N + 5], s2[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];

int main (int argc, char *argv[]) {
    scanf("%s%s", s1 + 1, s2 + 1);
    int n = strlen(s1 + 1), m = strlen(s2 + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s1[i] == s2[j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
