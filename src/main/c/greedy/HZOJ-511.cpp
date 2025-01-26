#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
    long long a, b, k, ans = 0;
    cin >> a >> b >> k;
    if (k == 1) {
        cout << b - a << endl;
        return 0;
    }
    if (k == 0) {
        if (b != 0) cout << b - a << endl;
        else cout << !!(a) << endl;
        return 0;
    }
    while (1) {
        if (a * k <= b) {
            ans += 1 + b % k;
            b /= k;
        } else {
            ans += b - a;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
