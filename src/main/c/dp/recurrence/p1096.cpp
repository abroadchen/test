#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

#define MAX_N 200





class BitInt: public vector<int> {
public:
    BitInt() { push_back(0); }
    BitInt(int x) {
        push_back(x);
        process_digit();
    }

    BitInt operator*(int x) {
        BitInt ret(*this);
        ret *= x;
        return ret;
    }
    BitInt &operator*=(int x) {
        for (int i = 0; i < size(); i++) {
            at(i) *= x;
        }
        process_digit();
        return *this;
    }

    BitInt operator+(int x) {
        BitInt ret(*this);
        ret += x;
        return ret;
    }
    BitInt &operator+=(int x) {
        at(0) += x;
        process_digit();
        return *this;
    }
private:
    void process_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return;
    }
};

BigInt f[MAX_N + 5];

ostream &operator<<(ostream &out, const BitInt &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    f[1] = 2;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] * 2 + 2;
    }
    cout << f[n] << endl;
    return 0;
}
