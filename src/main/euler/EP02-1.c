#include <stdio.h>
#define MAX_N 4000000

int fib[35] = {1, 1, 2};

int main() {
    int n = 2, sum = 0;
    while (fib[n - 1] + fib[n - 2] < MAX_N) {
        fib[n] = fib[n - 1] + fib[n - 2];
        if (fib[n] % 2 == 0) sum += fib[n];
        n += 1;
    }
    printf("%d\n", sum);
    return 0;
}
