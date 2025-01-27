#include <cstdio>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
using namespace std;


#define MAX_N 1000
#define MAX_K 10

class BigInt: public vector<int> {
public:
    BigInt() { push_back(0); }
    BigInt(int x) {
        this->push_back(x);
        process_digit();
    }

    BigInt &operator+=(const BigInt &a) {
        for (int i = 0; i < a.size(); i++) {
            if (i >= size()) push_back(a[i]);
            else at(i) += a[i];
        }
        process_digit();
        return *this;
    }

    BigInt operator+(const BigInt &a) {
        BigInt ret(*this);
        ret += a;
        return ret;
    }

    BigInt &operator*=(const int x) {
        for (int i = 0; i < size(); i++) at(i) *= x;
        process_digit();
        return *this;
    }
    BigInt operator*(const int x) {
        BigInt ret(*this);
        ret *= x;
        return ret;
    }

private:
    void process_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 100000) continue;
            if (i == size() - 1) push_back(0);
            at(i + 1) += at(i) / 100000;
            at(i) %= 100000;
        }
        return;
    }
};


ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}


BigInt f[MAX_N + 5];
int main (int argc, char *argv[]) {
    int n, k;
    scanf("%d%d", &n, &k);
    f[1] = k;
    f[2] = k * (k - 1);
    f[3] = k * (k - 1) * (k - 2);
    for (int i = 4; i <= n; i++) {
        f[i] = f[i - 1] * (k - 2);
        f[i] += f[i - 2] * (k - 1);
    }
    cout << f[n] << endl;
    return 0;
}
