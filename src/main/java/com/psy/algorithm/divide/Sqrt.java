public class Sqrt {

    static int mySqrt(int x) {
        int i = 1, j = x;
        int r = 0;
        while (i <= j) {
            int m = (i + j) >>> 1;
            if (m <= x / m) {
                i = m + 1;
                r = m;
            } else {
                j = m - 1;
            }
        }
        return r;
    }
}
