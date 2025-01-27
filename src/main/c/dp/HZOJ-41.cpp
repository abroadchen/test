#include <cstdio>
using namespace std;


#define MAX_N 1000
#define MAX_K 10
int f[MAX_N + 5][MAX_K + 5];


int main (int argc, char *argv[]) {
    int n, k;
    scanf("%d%d", &n, &k);
    f[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            f[i][j] = 0;
            for (int c = 0; c < k; c++) {
                if (c == j) continue;
                f[i][j] += f[i - 1][c];
            }
        }
    }
    long long sum = 0;
    for (int i = 1; i < k; i++) sum += f[n][i];
    printf("%lld\n", sum * k);
    return 0;
}
