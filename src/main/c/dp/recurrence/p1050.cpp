#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
    int n, k, base = 1, x, y;
    cin >> n >> k;
    for (int i = 0; i < k; i++, base *= 10);
    x = n % base;
    y = x;
    int cnt = 1;
    while (x * y % base != x) {
        cout << "y = " << y << "(" << cnt << ")";
        y = y * x % base;
        cnt += 1;
        if ((cnt - 1) % 4 == 0) cout << endl;
    }
    cout << cnt << endl;
    return 0;
}
