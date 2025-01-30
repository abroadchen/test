#include <iostream>
using namespace std;

#define MAX_N 500000
#define lowbit(x) ((x) & (-x))
int c[MAX_N + 5];

void add(int i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return;
}

int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int main (int argc, char *argv[]) {
    int n, m;
    cin >> n >> m;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        add(i, x, n);
    }
    for (int i = 0, x, y, z; i < m; i++) {
        cin >> z >> x >> y;
        if (z == 1) {
            add(x, y, n);
        } else {
            cout << query(y) - query(x - 1) << endl;
        }
    }
    return 0;
}
