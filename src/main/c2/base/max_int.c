

#include <cstdarg>
#include <cstdint>
#include <stdio.h>
#include <stdlib.h>

int max_int(int n, ...) {
    va_list args;
    va_start(args, n);
    int ans = INT32_MIN;
    for (int i = 0; i < n; i++) {
        int a = va_arg(args, int);
        if (a > ans) ans = a;
    }
    va_end(args);
    return ans;
}

int main(int argc, char *argv[])
{
    return 0;
}
