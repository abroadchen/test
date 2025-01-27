#include <algorithm>
#include <cstdio>
using namespace std;

#define MAX_N 1000
int val[MAX_N + 5][MAX_N + 5];
int f[MAX_N + 5][MAX_N + 5];


int main (int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &val[i][j]);
        }
    }
    f[1][1] = val[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= i - 1; j++) {
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + val[i][j];
        }
        f[i][1] = f[i - 1][1] + val[i][1];
        f[i][i] = f[i - 1][i - 1] + val[i][i];
    }
    int ans = f[n][1];
    for (int i = 2; i <= n; i++) {
        if (f[n][i] > ans) ans = f[n][i];
    }
    printf("%d\n", ans);
    return 0;
}
