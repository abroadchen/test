#include <iostream>
using namespace std;

#define MAX_N 200000
int a[MAX_N + 5];
int n;


int main (int argc, char *argv[]) {
    cin >> n;
    int pre = 0, sum = 0, ans = -10000;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (sum - pre > ans) ans = sum - pre;
        if (sum < pre) pre = sum;
    }
    cout << ans << endl;
    return 0;
}
