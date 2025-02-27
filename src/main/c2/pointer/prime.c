void init_prime(int n) {
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            prime[j] = 1;
        }
    }
    return;
}
