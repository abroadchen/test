
#include <stdio.h>
long long pentagonal(long long n) {
    return n * (3 * n - 1) / 2;
}

long long heaxgonal(long long n) {
    return n * (2 * n - 1);
}


int binary_search(long long val, long long (*func)(long long)) {
    long long head = 1, tail = val, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == val) return 1;
        if (func(mid) < val) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int main() {
    long long n = 144;
    while (binary_search(heaxgonal(n), pentagonal) == 0) n++;
    printf("%lld\n", heaxgonal(n));
    return 0;
}
