#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main (int argc, char *argv[]) {
    int w, n;
    cin >> w >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int i = 0, j = n - 1, cnt = 0;
    while (i < j) {
        if (arr[i] + arr[j] <= w) {
            i++, j--;
        } else j--;
        cnt += 1;
    }
    if (i == j) cnt += 1;
    cout << cnt << endl;
    return 0;
}
