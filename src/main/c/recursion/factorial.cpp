#include <iostream>
#include <stack>
using namespace std;


int f(int n) {
    if (n == 1) return 1;
    return n * f(n - 1);
}

struct Data {
    Data(int n, int *pre_ret): n(n), pre_ret(pre_ret) {
        code = 0;
    }
    int n;
    int code, ret, *pre_ret;
};

int non_f(int n) {
    stack<Data> s;
    int ans;
    Data d(n, &ans);
    s.push(d);
    while (!s.empty()) {
        Data &cur = s.top();
        switch (cur.code) {
            case 0: {
                if (cur.n == 1) {
                    *(cur.pre_ret) = 1;
                    s.pop();
                } else {
                    cur.code = 1;
                    s.push(cur);
                    s.push(d);
                }
            } break;
            case 1: {
                Data d(cur.n - 1, &(cur.ret));
                cur.code = 2;
                s.push(d);
            } break;
            case 2: {
                *(cur.pre_ret) = cur.ret * cur.n;
                s.pop();
            } break;
        }
    }
    return ans;
}


int main (int argc, char *argv[]) {
    int n;
    while (cin >> n) {
        cout << f(n) << endl;
        cout << non_f(n) << endl;
    }
    return 0;
}
