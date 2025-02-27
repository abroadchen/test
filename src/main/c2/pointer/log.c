

#define DEBUG 1
#define ERROR 2
#define FATAL 3
#define NO_LOG 4

#define LOG(level) \
if (level >= LOG_LEVEL) \
printf("[%s : %d] ", __FILE__, __LINE__), \
printf

int main() {
    int a = 123;
    printf("hello world\n");
    printf("a = %d\n", a);
    LOG(DEBUG)("hello world, DEBUG\n");
    LOG(ERROR)("hello world, ERROR\n");
    LOG(FATAL)("hello world, FATAL\n");
    LOG(DEBUG)("a = %d, DEBUG\n", a);
    LOG(ERROR)("a = %d, DEBUG\n", a);
    LOG(FATAL)("a = %d, DEBUG\n", a);
    return 0;
}


