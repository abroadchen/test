#include <algorithm>
#include <cstdio>
using namespace std;

#define MAX_V 10000
int dp[MAX_V + 5] = {0};



int main (int argc, char *argv[]) {
    int n, V;
    scanf("%d%d", &n, &V);
    for (int i = 1, c, v; i <= n; i++) {
        scanf("%d%d", &c, &v);
        for (int j = c;  j <= V;  j++) {
            dp[j] = max(dp[j], dp[j - c] + v);
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}
