#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_N 10000
int dp[MAX_N + 5];



int main (int argc, char *argv[]) {
    int n, ans = 0;
    cin >> n;
    for (int i = 1, t, j; i <= n; i++) {
        cin >> t;
        dp[i] = t;
        while (cin >> j) {
            if (j == 0) break;
            dp[i] = max(dp[i], dp[j] + t);
        }
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
    return 0;
}
