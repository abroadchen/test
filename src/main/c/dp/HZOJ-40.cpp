#include <iostream>
using namespace std;

#define MAX_N 500
int f[MAX_N + 5];



int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    f[0] = 1;
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 2] + f[i - 3];
    }
    cout << f[n] << endl;
    return 0;
}
