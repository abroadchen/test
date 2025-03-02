#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
void r_access() {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("failed to open file\n");
        exit(1);
    }
    char s[100];
    fscanf(fp, "%[^\n]", s);
    printf("s = %s\n", s);
    fclose(fp);
    fp = fopen("temp.txt", "r");
    if (fp == NULL) {
        printf("failed to open file\n");
    }
    return;
}

void rand_file_name(char *file_name, int n) {
    for (int i = 0; i < n; i++) {
        file_name[i] = rand() % 26 + 'a';
    }
    file_name[n] = 0;
    strcat(file_name, ".txt");
    return;
}


void w_access() {
    FILE *fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("failed to open file\n");
        exit(1);
    }
    fprintf(fp, "hahahah, world\n");
    fprintf(fp, "hello world\n");
    fclose(fp);
    char file_name[100] = {0};
    rand_file_name(file_name, 10);
    fp = fopen(file_name, "w");
    fclose(fp);
    return;
}

void r_plus_access() {
    FILE *fp = fopen("data.txt", "r+");
    if (fp == NULL) {
        printf("failed to open file\n");
        exit(1);
    }
    char s[100];
    fscanf(fp, "%s", s);
    printf("r+: s = %s\n", s);
    fprintf(fp, "00000");
    fclose(fp);
    fp = fopen("temp.txt", "r+");
    if (fp == NULL) {
        printf("failed to open file\n");
    }
    return;
}



int main() {
    srand(time(0));
    r_access();
    w_access();
    return 0;
}
