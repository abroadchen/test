public class QuickPow {

    static double myPow(double x, int n) {
        long p = n;
        if (p < 0) {
            p = -p;
        }
        double r = myPowPositive(x, p);
        return n < 0 ? 1 / r : r;
    }

    static double myPowPositive(double x, long n) {
        if (n == 0) {
            return 1.0;
        }
        if (n == 1) {
            return x;
        }
        double y = myPow(x, n / 2);
        if ((n & 1) == 0) {
            return y * y;
        } else {
            return x * y * y;
        }
    }
}
