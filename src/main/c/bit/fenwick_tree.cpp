#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_N 10000
#define lowbit(x) ((x) & (-x))
int a[MAX_N];
int c[MAX_N];


void add(int i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return;
}


int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}



int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, a[i], n);
    }
    cout << "a: ";
    for (int i = 1; i <= n; i++) {
        printf("%4d", a[i]);
    }
    cout << endl;
    cout << "c: ";
    for (int i = 1; i <= n; i++) {
        printf("%4d", c[i]);
    }
    cout << endl;
    cout << "s: ";
    for (int i = 1; i <= n; i++) {
        printf("%4d", query(i));
    }
    cout << endl;
    return 0;
}
