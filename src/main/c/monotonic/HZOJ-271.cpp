#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main (int argc, char *argv[]) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    deque<int> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        while (!q.empty() && arr[q.back()] > arr[i]) q.pop_back();
        q.push_back(i);
        if (i - q.front() == k) q.pop_front();
        if (i + 1 < k) continue;
        if (i >= k) cout << " ";
        cout << arr[q.front()];
    }
    cout << endl;
    q.clear();
    for (int i = 0; i < n; i++) {
        while (!q.empty() && arr[q.back()] < arr[i]) q.pop_back();
        q.push_back(i);
        if (i - q.front() == k) q.pop_front();
        if (i + 1 < k) continue;
        if (i >= k) cout << " ";
        cout << arr[q.front()];
    }
    cout << endl;
    return 0;
}
