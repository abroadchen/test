#include <cstdint>
#include <cstdio>
#include <iostream>
#include <numeric>
using namespace std;

#define int long long
#define MAX_N 1000000
int n, m, qwq, maxd = 1, ans = 0;
int a[MAX_N + 5], s[MAX_N + 5];


void build(int l, int r, int k) {
    if (l == r) {
        s[l] = 2 * maxd - maxd / k;
        ans += a[l] * s[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, k * 2);
    build(mid + 1, r, k * 2);
    return;
}


int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}


int32_t main (int32_t argc, char *argv[]) {
    scanf("%lld%lld%lld", &n, &m, &qwq);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    while (maxd <= n) maxd *= 2;
    build(1, n, 1);
    for (int i = 2; i <= n; i++) s[i] += s[i - 1];
    int k = gcd(maxd, qwq);
    maxd /= k, qwq /= k;
    for (int i = 1, l, r, x; i <= m; i++) {
        scanf("%lld%lld%lld", &l, &r, &x);
        ans += x * (s[r] - s[l - 1]);
        cout << ans / maxd * qwq << endl;
    }
    return 0;
}
