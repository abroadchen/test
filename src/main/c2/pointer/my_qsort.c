#include <_string.h>
#include <cstring>
#include <stddef.h>
#include <stdlib.h>



void swap1(void *x, void *y, size_t size) {
    char *a = (char *)x;
    char *b = (char *)y;
    char c;
    for (int i = 0; i < size; i++) {
        if (a[i] == b[i]) continue;
        c = a[i];
        a[i] = b[i];
        b[i] = c;
    }
    return;
}


void swap(void *x, void *y, size_t size, void *buff) {
    memmove(buff, x, size);
    memmove(x, y, size);
    memmove(y, buff, size);
    return;
}



void my_qsort(void *arr, size_t count, size_t size, int (*comp)(const void *, const void *)) {
    if (count <= 1) return;
    void *x = arr;
    void *y = arr + (count - 1) * size;
    void *z = malloc(size), *buff = malloc(size);
    memcpy(z, arr, size);
    do {
        while (comp(x, z) < 0) x += size;
        while (comp(z, y) < 0) y -= size;
        if (x <= y) {
            swap(x, y, size, buff);
            x += size, y -= size;
        }
    } while (x <= y);
    size_t cnt1 = y < arr ? 0 : (y - arr) / size + 1;
    size_t cnt2 = count - (x - arr) / size;
    my_qsort(arr, cnt1, size, comp);
    my_qsort(x, cnt2, size, comp);
    return;
}
