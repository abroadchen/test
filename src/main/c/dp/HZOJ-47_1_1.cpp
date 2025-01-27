#include <algorithm>
#include <cstdio>
using namespace std;


#define MAX_N 100
#define MAX_V 10000
int dp[MAX_V + 5] = {0};


int main (int argc, char *argv[]) {
    int V, n;
    scanf("%d%d", &V, &n);
    for (int i = 1, v, w; i <= n; i++) {
        scanf("%d%d", &v, &w);
        for (int j = V; j >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}
