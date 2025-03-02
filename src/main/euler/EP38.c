#include <math.h>
#include <stdio.h>
#define MAX_N 10000

int digits(int n) {
    return floor(log10(n)) + 1;
}


int calc(int x) {
    int n = 1, ans = 0;
    while (digits(ans) < 9) {
        ans *= (int)pow(10, digits(x * n));
        ans += x * n;
        n += 1;
    }
    if (digits(ans) - 9) return 0;
    int num[10] = {0};
    num[0] = 1;
    int temp = ans;
    while (temp) {
        if (num[temp % 10]) return 0;
        num[temp % 10] += 1;
        temp /= 10;
    }
    return ans;
}


int main() {
    int ans = 0;
    for (int i = 1; i < MAX_N; i++) {
        int temp = calc(i);
        if (temp > ans) ans = temp;
    }
    printf("%d\n", ans);
    return 0;
}
