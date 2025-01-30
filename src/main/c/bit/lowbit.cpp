#include <iostream>
using namespace std;

#define lowbit(x) ((x) & (-x))

int main (int argc, char *argv[]) {
    int x;
    cin >> x;
    cout << x << " = ";
    while (x) {
        cout << lowbit(x);
        x -= lowbit(x);
        if (x) cout << " + ";
    }
    cout << endl;
    return 0;
}



