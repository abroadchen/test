#include <iostream>
#include <string>
using namespace std;

int main (int argc, char *argv[]) {
    string a = "abcdefgcde", b = "cde", c = "xxx";
    cout << a << " " << b << endl;
    int pos = -1;
    while (1) {
        pos = a.find(b, pos + 1);
        cout << pos << endl;
        if (pos == -1) break;
        a.erase(pos, b.size());
        a.insert(pos, c);
    }
    return 0;
}
