#include <stdio.h>

#define MAX_N 2540160
int main() {
    int n = 1;
    for (int i = 1; i < 10; i++) {
        n *= i;
    }
    printf("%d\n", n * 7);
    return 0;
}
