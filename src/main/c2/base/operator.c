
#include <stdio.h>
#define PRINT(stmt, func) { \
    printf("%s\n", #stmt); \
    stmt; \
    func; \
}


void print_digit(int x) {
    for (int i = 31; i >= 0; i--) {
        printf("%c", (x & (1 << i)) ? '1' : '0');
    }
    return;
}


int main(int argc, char *argv[])
{
    int a = 5, b = 2, c = 7, d;
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    PRINT(a = c, printf(""));
    a ^= b; b ^= a; a ^= b;
    // /向0取整 << 向下取整 正数无差别 负数不一样
    return 0;
}
