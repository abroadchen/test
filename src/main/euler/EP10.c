
#include <stdio.h>
#define MAX_N 2000000

int prime[MAX_N + 5] = {0};

void init_prime() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1, I = prime[0]; j <= I; j++) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return;
}


int main() {
    init_prime();
    long long sum = 0;
    for (int i = 1; i <= prime[0]; i++) {
        sum += prime[i];
    }
    printf("%lld\n", sum);
    return 0;
}
