#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> PII;


int main (int argc, char *argv[]) {
    int n, m, t = 0;
    cin >> n >> m;
    set<PII> s;
    s.insert(PII(0, t++));
    for (int i = 0; i < n; i++) {
        int i1 = i % 2, i2 = 1 - i1;
        vector<int> temp;
        for (auto x: s) {
            temp.push_back(x.first);
        }
        s.clear();
        for (int j = 0, a; j < m; j++) {
            cin >> a;
            for (auto x: temp) {
                if (s.size() < m || s.begin()->first < x - a) s.insert(PII(x - a, t++));
                if (s.size() > m) s.erase(s.begin());
            }
        }
    }
    int flag = 0;
    for (auto iter = s.rbegin(); iter != s.rend(); iter++) {
        if (flag) cout << " ";
        cout << -iter->first << endl;
        flag = 1;
    }
    cout << endl;
    return 0;
}
