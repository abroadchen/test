#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


string s;
int z[10000];


int main (int argc, char *argv[]) {
    cin >> s;
    int l, r;
    l = r = -1;
    z[0] = s.size();
    for (int i = 1, n = s.size(); i < n; i++) {
        if (r >= i) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    for (int i = 0; i < s.size(); i++) {
        cout << z[i] << " ";
    }
    cout << endl;
    return 0;
}
