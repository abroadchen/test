#include <algorithm>
#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
    int n, pre_dp = 0, dp, ans = 0x80000000;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (pre_dp > 0) dp = pre_dp + x;
        else dp = x;
        ans = max(ans, dp);
        pre_dp = dp;
    }
    cout << ans << endl;
    return 0;
}
