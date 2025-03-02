#include <stdio.h>

int is_reverse(int n, int base) {
    int temp = 0, x = n;
    while (x) {
        temp = temp * base + x % base;
        x /= base;
    }
    return temp == n;
}

int main() {
    int ans = 0;
    for (int a = 999; a >= 100; a--) {
        for (int b = a; b >= 100; b--) {
            if (a * b <= ans || !is_reverse(a * b, 10)) continue;
            ans = a * b;
            printf("%d * %d = %d\n", a, b, ans);
        }
    }
    printf("ans = %d\n", ans);
    return 0;
}
