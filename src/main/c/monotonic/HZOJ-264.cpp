#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

int main (int argc, char *argv[]) {
    long long n;
    scanf("%lld", &n);
    vector<long long> arr(n + 2, -1), l(n + 2), r(n + 2);
    for (long long i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
    }
    stack<long long> s;
    for (long long i = 1; i <= n + 1; i++) {
        while (!s.empty() && arr[i] < arr[s.top()]) {
            r[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (long long i = n; i >= 0; i--) {
        while (!s.empty() && arr[i] < arr[s.top()]) {
            l[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        long long height = arr[i], width = r[i] - l[i] - 1;
        ans = max(ans, height * width);
    }
    printf("%lld\n", ans);
    return 0;
}
