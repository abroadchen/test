#include <cstdio>
#include <stdatomic.h>
#include <stdio.h>
int main() {
    FILE *fp = fopen("data5.txt", "w");
    printf("ftell(fp) = %ld\n", ftell(fp));
    fprintf(fp, "0123456789");
    printf("after print 0123456789 ftell(fp) = %ld\n", ftell(fp));
    fseek(fp, 2, SEEK_SET);
    printf("after fseek(2) ftell(fp) = %ld\n", ftell(fp));
    fprintf(fp, "abc");
    printf("after print abc ftell(fp) = %ld\n", ftell(fp));


    fseek(fp, 0, SEEK_END);//将文件位置设置到结尾
    fseek(fp, 0, SEEK_SET);//将文件位置设置到开头
    fclose(fp);
    return 0;
}
