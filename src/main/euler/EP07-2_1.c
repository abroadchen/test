
#include <stdio.h>
#define MAX_N 200000

int prime[MAX_N + 5] = {0};

void init_prime() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
        for (int j = 2; j <= MAX_N / i; j++) {
            prime[i * j] = 1;
        }
    }
    return;
}


int main() {
    init_prime();
    for (int i = 1; i <= prime[0]; i++) {
        printf("%d\n", prime[i]);
    }
    printf("%d\n", prime[10001]);
    return 0;
}
