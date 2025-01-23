#include <cstdlib>
#include <iostream>
#include <ostream>
#include <set>
#include <utility>
using namespace std;

void test1() {
    cout << "set base usage" << endl;
    set<int> s;
    cout << s.size() << endl;
    s.insert(3);
    cout << s.size() << endl;
    s.insert(4);
    cout << s.size() << endl;
    s.insert(2);
    cout << s.size() << endl;
    return;
}

void test2() {
    cout << "set item unique feature: " << endl;
    set<int> s;
    cout << s.size() << endl;
    s.insert(3);
    cout << s.size() << endl;
    s.insert(4);
    cout << "insert 4: " << s.size() << endl;
    s.insert(4);
    cout << "insert 4: " << s.size() << endl;
    return;
}

void test3() {
    cout << "set item unique feature: " << endl;
    typedef pair<int, int> PII;
    set<PII> s;
    int tot = 0;
    cout << s.size() << endl;
    s.insert(PII(3, tot++));
    cout << s.size() << endl;
    s.insert(PII(4, tot++));
    cout << "insert 4: " << s.size() << endl;
    s.insert(PII(4, tot++));
    cout << "insert 4: " << s.size() << endl;
    return;
}

void test4() {
    cout << "foreach set item unique feature: " << endl;
    typedef pair<int, int> PII;
    set<PII> s;
    int tot = 0;
    s.insert(PII(4, tot++));
    s.insert(PII(3, tot++));
    s.insert(PII(4, tot++));
    for (auto x: s) {
        cout << "(" << x.first << ", " << x.second << ")" << endl;
    }
    return;
}

void test5() {
    cout << "set replace heap: " << endl;
    typedef pair<int, int> PII;
    set<PII> s;
    int tot = 0;
    for (int i = 0; i < 10; i++) {
        s.insert(PII(rand() % 20, tot++));
    }
    for (int i = 0; i < 4; i++) {
        cout << "s.begin() = " << s.begin()->first << endl;
        s.erase(s.begin());
    }
    for (auto x: s) {
        cout << "(" << x.first << ", " << x.second << ")" << endl;
    }
    return;
}

int main (int argc, char *argv[]) {
    
    return 0;
}
