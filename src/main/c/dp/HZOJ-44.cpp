#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;


#define MAX_N 1000000
int val[MAX_N + 5];
int dp[MAX_N + 5] = {0};


int main (int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", val + i);
    }
    val[0] = INT32_MIN;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (val[j] < val[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}
