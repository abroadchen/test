#include <stdio.h>

int is_reverse(int n) {
    int temp = 0, x = n;
    while (x) {
        temp = temp * 10 + x % 10;
        x /= 10;
    }
    return temp == n;
}

int main() {
    int ans = 0;
    for (int a = 100; a < 1000; a++) {
        for (int b = 100; b < 1000; b++) {
            if (is_reverse(a * b) && a * b > ans) {
                ans = a * b;
                printf("%d * %d = %d\n", a, b, ans);
            }
        }
    }
    printf("ans = %d\n", ans);
    return 0;
}
