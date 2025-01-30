#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


#define MAX_N 2000
string word[MAX_N + 5];
int dp[MAX_N + 5] = {0};



bool is_prefix(int j, int i) {
    if (word[j].size() >= word[i].size()) return false;
    for (int k = 0; word[j][k]; k++) {
        if (word[j][k] - word[i][k]) return false;
    }
    return true;
}



int main (int argc, char *argv[]) {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word[i];
    }
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (is_prefix(j, i)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
