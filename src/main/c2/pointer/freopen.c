#include <stdio.h>
int main() {
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    printf("hello freopen, stdout\n");
    char s[1000];
    int i = 1;
    while (scanf("%[^\n]", s) != EOF) {
        getchar();
        fprintf(stderr, "%d test case\n", i++);
        printf("%s | hello world\n", s);
    }
}
