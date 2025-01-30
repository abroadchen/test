#include <iostream>
using namespace std;

int n;
int a[100005];


int main (int argc, char *argv[]) {
    int n, ans;
    cin >> n;
    cin >> a[1];
    ans = a[1];
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        if (a[i] > a[i - 1]) ans += (a[i] - a[i - 1]);
    }
    cout << ans << endl;
    return 0;
}
