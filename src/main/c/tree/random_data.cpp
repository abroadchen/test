#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int main (int argc, char *argv[]) {
    srand(time(0));
    printf("26\n");
    for (int i = 0; i < 26; i++) {
        printf("%c %d\n", 'a' + i, rand() % 100000);
    }
    return 0;
}
