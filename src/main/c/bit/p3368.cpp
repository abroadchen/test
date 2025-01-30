#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_N 500000
#define lowbit(x) ((x) & (-x))
int a[MAX_N + 5];
int c[MAX_N + 5];

void add(int i, int x, int n) {
    if (i > n) return;
    c[i] += x;
    add(i + lowbit(i), x, n);
    return;
}

int query(int i) {
    if (i == 0) return 0;
    return c[i] + query(i - lowbit(i));
}



int main (int argc, char *argv[]) {
    int n, m;
    cin >> n >> m;
    for (int i = 1, pre = 0, x; i <= n; i++) {
        cin >> x;
        add(i, x - pre, n);
        pre = x;
    }
    for (int i = 1, z; i <= m; i++) {
        cin >> z;
        if (z == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            add(x, k, n);
            add(y + 1, -k, n);
        } else {
            int x;
            cin >> x;
            cout << query(x) << endl;
        }
    }
    return 0;
}
