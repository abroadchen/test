#include <stdio.h>
#define MAX_N 4000000


int main() {
    int a = 1, b = 2, sum = 2;
    while (a + b < MAX_N) {
        //a = a + b;
        //a ^= b;
        //b ^= a;
        //a ^= b;
        b = a + b;
        a = b - a;
        if (!(b & 1)) sum += b;
    }
    printf("%d\n", sum);
    return 0;
}
