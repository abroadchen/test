#include <cstdio>
#include <stdexcept>
using namespace std;

#define MAX_N 1000000
int n, m;
long long a[MAX_N + 5];
long long x[MAX_N + 5];

struct Data {
    long long d, s, t;
};
Data ods[MAX_N + 5];



bool check(int k) {
    x[1] = a[1];
    for (int i = 2; i <= n; i++) {
        x[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= k; i++) {
        long long d = ods[i].d, s = ods[i].s, t = ods[i].t;
        x[s] -= d;
        x[t + 1] += d;
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += x[i];
        if (sum < 0) return 1;
    }
    return 0;
}


//00001111
int binary_search() {
    int l = 1, r = m + 1, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (check(mid) == 0) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main (int argc, char *argv[]) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld%lld", &ods[i].d, &ods[i].s, &ods[i].t);
    }
    int ind = binary_search();
    if (ind == m + 1) {
        printf("0\n");
    } else {
        printf("-1\n");
        printf("%d\n", ind);
    }
    return 0;
}
