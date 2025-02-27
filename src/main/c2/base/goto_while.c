#include <stdio.h>
int main(void)
{
    int n, i = 1;
    scanf("%d", &n);
judge:
    if (i <= n) goto stmt;
    else goto while_end;
stmt:
    printf("%d ", i);
    i += 1;
    goto judge;
while_end:
    printf("\n");
    return 0;
}
