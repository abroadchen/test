#include "sort_test.h"
#include <stack>
using namespace std;

void quick_sort(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1) return;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return;
    }
    int x = l, y = r - 1, z = arr[l];
    while (x < y) {
        while (x < y && z <= arr[y]) --y;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= z) ++x;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quick_sort(arr, l, x);
    quick_sort(arr, x + 1, r);
    return;
}

struct Data {
    Data(int *arr, int l, int r): arr(arr), l(l), r(r) {
        code = 0;
    }
    int *arr, l, r;
    int x;
    int code;
};

void non_quick_sort(int *arr, int l, int r) {
    stack<Data> s;
    Data d(arr, l, r);
    s.push(d);
    while (!s.empty()) {
        Data &cur = s.top();
        switch (cur.code) {
            case 0: {
                if (cur.r - cur.l <= 2) {
                    if (cur.r - cur.l <= 1) s.code = 4;
                    if (cur.arr[cur.l] > cur.arr[cur.l + 1]) swap(cur.arr[cur.l], cur.arr[cur.l + 1]);
                    s.code = 4;
                } else cur.code = 1;
            } break;
            case 1: {
                int x = cur.l, y = cur.r - 1, z = cur.arr[cur.l];
                while (x < y) {
                    while (x < y && z <= cur.arr[y]) --y;
                    if (x < y) cur.arr[x++] = cur.arr[y];
                    while (x < y && cur.arr[x] <= z) ++x;
                    if (x < y) cur.arr[y--] = cur.arr[x];
                }
                cur.arr[x] = z;
                cur.x = x;
                cur.code = 2;
            } break;
            case 2: {
                Data d(cur.arr, cur.l, cur.x);
                cur.code = 3;
                s.push(d);
            } break;
            case 3: {
                Data d(cur.arr, cur.x + 1, cur.r);
                cur.code = 4;
                s.push(d);
            } break;
            case 4: {
                s.pop();
            } break;
        }
    }
    return;
}




int main (int argc, char *argv[]) {
    int *arr_s = getRandData(SMALL_DATA_N);
    int *arr_b = getRandData(BIG_DATA_N);
    TEST(quick_sort, arr_s, SMALL_DATA_N);
    TEST(quick_sort, arr_b, BIG_DATA_N);
    free(arr_s);
    free(arr_b);
    return 0;
}
