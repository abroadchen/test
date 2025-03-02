

#include <stdio.h>
int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    long long ans = 1;
    for (int i = 2; i <= 20; i++) {
        ans = lcm(ans, i);
    }
    printf("%lld\n", ans);
    return 0;
}
