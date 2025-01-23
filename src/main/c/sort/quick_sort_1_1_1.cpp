#include "sort_test.h"
using namespace std;


int three_point_select(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return b;
}


void quick_sort(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1) return;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return;
    }
    while (l < r) {
        int x = l, y = r - 1;
        int z = three_point_select(
            arr[l],
            arr[r - 1],
            arr[(l + r) / 2]
        );
        do {
            while (arr[x] < z) ++x;
            while (arr[y] > z) --y;
            if (x <= y) {
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while (x <= y);
        quick_sort(arr, l, x);
        l = x;
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
