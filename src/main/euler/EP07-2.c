
#include <stdio.h>
#define MAX_N 100

int prime[MAX_N + 5] = {0};

void init_prime() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i] == 0) {
            for (int j = 2; j <= MAX_N / i; j++) {
                prime[i * j] = 1;
            }
        }
    }
    return;
}


int main() {
    init_prime();
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i] == 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}
