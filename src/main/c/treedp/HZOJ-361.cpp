#include <algorithm>
#include <iostream>
using namespace std;

struct Edge {
    int to, nxt;
} e[6005];
int head[6005], cnt = 0;

void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return;
}
int n, h[6005];
int fa[6005], dp[6005][2];

void getDP(int x) {
    dp[x][0] = 0;
    dp[x][1] = h[x];
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to;
        getDP(to);
        dp[x][0] += max(dp[to][0], dp[to][1]);
        dp[x][1] += dp[to][0];
    }
}

int main (int argc, char *argv[]) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1, a, b; i <= n; i++) {
        cin >> a >> b;
        add(b, a);
        fa[a] = 1;
    }
    int root;
    for (int i = 1; i <= n; i++) {
        if (fa[i]) continue;
        root = i;
        break;
    }
    getDP(root);
    cout << max(dp[root][0], dp[root][1]) << endl;
    return 0;
}
