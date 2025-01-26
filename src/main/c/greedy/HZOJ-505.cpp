#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}



int main (int argc, char *argv[]) {
    vector<string> arr;
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
