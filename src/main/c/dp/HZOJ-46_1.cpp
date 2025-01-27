#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;


#define MAX_N 500000
char s[MAX_N + 5];
int dp[MAX_N + 5];
vector<int> g[MAX_N + 5];

int is_palindrome(int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++, j--;
    }
    return 1;
}


void extract(int i, int j) {
    while (s[i] == s[j]) {
        g[i].push_back(j - 1);
        i++, j--;
    }
    return;
}


int main (int argc, char *argv[]) {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        extract(i, i);
        extract(i, i + 1);
    }
    dp[0] = -1;
    for (int i = 1; s[i]; i++) {
        dp[i] = i;
        for (auto j: g[i]) {
            dp[i] = min(dp[i], dp[j] + 1);
        }
        //for (int j = 0; j < i; j++) {
        //    if (!is_palindrome(j + 1, i)) continue;
        //    dp[i] = min(dp[i], dp[j] + 1);
        //}
    }
    printf("%d\n", dp[n]);
    return 0;
}
