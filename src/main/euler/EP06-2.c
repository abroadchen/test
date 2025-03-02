#include <stdio.h>
#define MAX_N 100
int main() {
    int sum1 = 0, sum2 = 0;
    sum1 = (1 + n) * n >> 1;
    sum2 = n * (n + 1) * (2 * n + 1) / 6;
    printf("%d\n", sum1 * sum1 - sum2);
    return 0;
}
