

#include <stdio.h>
#include <stdlib.h>



void print(int n) {
    if (n == 1) {
        printf("%d\n", n);
        return;
    }
    print(n - 1);
    printf("%d\n", n);
    return;
}

int cnt = 100;
int main(int argc, char *argv[])
{
    int n = cnt;
    cnt -= 1;
    if (n == 1) {
        printf("%d\n", n);
        return 0;
    }
    main();
    printf("%d\n", n);
    return 0;
}
