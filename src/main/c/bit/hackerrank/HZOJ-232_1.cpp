#include <iostream>
using namespace std;


#define MAX_N 5000
int g[MAX_N + 5][MAX_N + 5];


int main (int argc, char *argv[]) {
    int n, R, max_x = 0, max_y = 0;
    cin >> n >> R;
    max_x = R, max_y = R;
    for (int i = 0, x, y, w; i < n; i++) {
        cin >> x >> y >> w;
        g[x + 1][y + 1] = w;
        if (x + 1 > max_x) max_x = x + 1;
        if (y + 1 > max_y) max_y = y + 1;
    }
    for (int i = 1; i <= max_x; i++) {
        for (int j = 1; j <= max_y; j++) {
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= max_x - R + 1; i++) {
        for (int j = 1; j <= max_y - R + 1; j++) {
            int k = i + R - 1, l = j + R - 1;
            int val = g[k][l] - g[i - 1][l] - g[k][j - 1] + g[i - 1][j - 1];
            if (val > ans) ans = val;
        }
    }
    cout << ans << endl;
    return 0;
}
