#ifndef _SORT_TEST_H
#define _SORT_TEST_H

#include <cstdio>
#include <cstdlib>
#include <ctime>

#define SMALL_DATA_N 5000
#define BIG_DATA_N 10000000

__attribute__((constructor))
void __init_Rand__() {
    printf("init rand\n");
    srand(time(0));
}

bool check(int *arr, int l, int r) {
    for (int i = l + 1; i < r; i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

int *getRandData(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
    return arr;
}

#define swap(a, b) { \
    __typeof(a) __c = (a); \
    (a) = (b), (b) = __c; \
}

#define TEST(func, arr, n) { \
    printf("TEST %s: ", #func); \
    int *temp = (int *)malloc(sizeof(int) * n); \
    memcpy(temp, arr, sizeof(int) * n); \
    long long b = clock(); \
    func(temp, 0, n); \
    long long e = clock(); \
    if (check(temp, 0, n)) { \
        printf("OK\t");
    } else { \
        printf("Failed "); \
    } \
    printf("%ditems %lld ms\n", n, (e - b) * 1000 / CLOCKS_PER_SEC); \
    free(temp); \
}




#endif // !SORT_TEST_H
