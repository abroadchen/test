#include <stdatomic.h>
#include <stdio.h>
int main() {
    freopen("/dev/ttys001", "w", stdout);
    char s[1000];
    while (scanf("%s", s) != EOF) {
        printf("from ttys001: %s\n", s);
    }
}
