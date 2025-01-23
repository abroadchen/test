#include "sort_test.h"
using namespace std;

#define MAX_N 10000

void selection_sort(int *arr, int l, int r) {
    for (int i = l, I = r - 1; i < I; i++) {
        int ind = i;
        for (int j = i + 1; j < r; j++) {
            if (arr[j] < arr[ind]) ind = j;
        }
        swap(arr[i], arr[ind]);
    }
    return;
}

int main (int argc, char *argv[]) {
    int *arr = getRandData(SMALL_DATA_N);
    TEST(selection_sort, arr, SMALL_DATA_N);
    free(arr);
    return 0;
}
