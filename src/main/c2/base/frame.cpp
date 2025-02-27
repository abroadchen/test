#include <cstdio>
using namespace std;




int main (int argc, char *argv[]) {
    char s[100], t[100];
    scanf("%[^\n]", s);
    int n;
    n = sprintf(t, "| %s |", s);
    for (int i = 0; i < n; i++) printf("-");
    printf("\n");
    printf("| %s |\n", s);
    for (int i = 0; i < n; i++) printf("-");
    printf("\n");
    return 0;
}
