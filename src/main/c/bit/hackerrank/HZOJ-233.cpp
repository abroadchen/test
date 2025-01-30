#include <iostream>
#include <set>
#include <utility>
using namespace std;


#define MAX_N 10000
int x[MAX_N + 5];
set<pair<int, int>> s;

int main (int argc, char *argv[]) {
    int n, p, h, m;
    cin >> n >> p >> h >> m;
    x[1] = h;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (s.find({a, b}) != s.end()) continue;
        x[a + 1] -= 1;
        x[b] += 1;
        s.insert({a, b});
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += x[i];
        cout << sum << endl;
    }
    return 0;
}
