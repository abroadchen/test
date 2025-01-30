#include <algorithm>
#include <cstdio>
using namespace std;


#define MAX_N 3100000
int node[MAX_N + 5][2];
int cnt = 1, root = 1;

void insert(int x) {
    int p = root;
    for (int i = 30; i >= 0; i--) {
        int ind = !!(x & (1 << i));//非零->1 0还是0 逻辑归一
        if (node[p][ind] == 0) node[p][ind] = ++cnt;
        p = node[p][ind];
    }
    return;
}


int query(int x) {
    int ans = 0, p = root;
    for (int i = 30; i >= 0; i--) {
        int ind = !!(x & (1 << i));
        if (node[p][1 - ind] != 0) {
            ans |= 1 << i;
            p = node[p][1 - ind];
        } else {
            p = node[p][ind];
        }
    }
    return ans;
}


int main (int argc, char *argv[]) {
    int n, ans = 0, temp;
    scanf("%d", &n);
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        insert(a);
        temp = query(a);
        ans = max(ans, temp);
    }
    printf("%d\n", ans);
    return 0;
}
