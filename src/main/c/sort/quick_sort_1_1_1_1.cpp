#include "sort_test.h"
using namespace std;


int three_point_select(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return b;
}

#define threshold 16

void __quick_sort(int *arr, int l, int r) {
    while (r - l > threshold) {
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



void unguarded_insert_sort(int *arr, int l, int r) {
    int ind = l;
    for (int i = l + 1; i < r; i++) {
        if (arr[i] < arr[ind]) ind = i;
    }
    while (ind > l) {
        swap(arr[ind], arr[ind - 1]);
        ind -= 1;
    }
    for (int i = l + 1; i < r; i++) {
        int j = i;
        while (arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j -= 1;
        }
    }
}

void quick_sort(int *arr, int l, int r) {
    __quick_sort(arr, l, r);
    unguarded_insert_sort(arr, l, r);
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
