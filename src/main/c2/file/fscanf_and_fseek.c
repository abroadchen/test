#include <cstdio>
#include <stdio.h>
int main() {
    FILE *fp = fopen("data5.txt", "r");
    int n;
    fseek(fp, 5, SEEK_SET);
    fscanf(fp, "%d", &n);
    printf("fscanf n = %d\n", n);
    fclose(fp);
    return 0;
}
