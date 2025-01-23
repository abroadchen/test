#include "sort_test.h"
using namespace std;

int *buff;
void merge_sort(int *arr, int l, int r) {
    if (r - l <= 1) return;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid, r);
    int p1 = l, p2 = mid, k = 0;
    while (p1 < mid || p2 < r) {
        if (p2 == r || (p1 < mid && arr[p1] <= arr[p2])) buff[k++] = arr[p1++];
        else buff[k++] = arr[p2++];
    }
    for (int i = l; i < r; i++) arr[i] = buff[i - l];
    return;
}


int main (int argc, char *argv[]) {
    buff = (int *)malloc(sizeof(int) * BIG_DATA_N);
    free(buff);
    return 0;
}
