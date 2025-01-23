#include "sort_test.h"
using namespace std;

void bubble_sort(int *arr, int l, int r) {
    for (int i = r - 1, I = l + 1, cnt; i >= I; i--) {
        cnt = 0;
        for (int j = l; j < i; j++) {
            if (arr[j] <= arr[j + 1]) continue;
            swap(arr[j], arr[j + 1]);
            cnt += 1;
        }
        if (cnt == 0) break;
    }
    return;
}


int main (int argc, char *argv[]) {
    
    return 0;
}
