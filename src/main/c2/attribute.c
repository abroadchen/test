#include <stdio.h>

int arr[10];

__attribute__((constructor))
void test1() {
    printf("hello test1\n");
    arr[0] = 100;
    return;
}


__attribute__((constructor))
void test2() {
    printf("hello test2\n");
    arr[2] = 99;
    return;
}


int main() {
    printf("hello main\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
