#include <stdio.h>
int main(int argc, char *argv[], char **env)
{
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    for (char **p = env; p[0]; p += 1) {
        printf("%s\n", p[0]);
    }
    return 0;
}
