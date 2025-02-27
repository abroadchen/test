
int digit(long long n, long long k) {
    if (k == 1) return n % 10;
    return digit(n / 10, k - 1);
}

int main(void)
{

    return 0;
}
