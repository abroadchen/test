#include <stdio.h>
#define MAX_N 15

int dfs(int i, int j, int n) {
    if (i == n) return 0;
    return max(dfs(i + 1, j, n), dfs(i + 1, j + 1, n)) + val[i][j];
}



int val[MAX_N + 5][MAX_N + 5];
int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &val[i][j]);
        }
    }
    printf("%d\n", dfs(0, 0, MAX_N));
    return 0;
}
