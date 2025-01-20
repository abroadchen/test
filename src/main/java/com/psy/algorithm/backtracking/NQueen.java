public class NQueen {


    public static void main(String[] args) {
        int n = 4;
        boolean[] ca = new boolean[n];//列
        boolean[] cb = new boolean[2 * n - 1];//左斜线 i + j
        boolean[] cc = new boolean[2 * n - 1];//右斜线 n - 1 - (i-j)
        char[][] table = new char[n][n];
        for (char[] t: table) {
            for (int i = 0; i < t.length; i++) {
                t[i] = '.';
            }
        }
        dfs(0, n, table, ca, cb, cc);
    }

    static void dfs(int i, int n, char[][] table, boolean[] ca, boolean[] cb, boolean[] cc) {
        if (i == n) {
            for (char[] t: table) {
                System.out.println(new String(t));
            }
            return;
        }
        for (int j = 0; j < n; j++) {
            if (ca[j] || cb[i + j] || cc[n - 1 - (i - j)]) {
                continue;
            }
            table[i][j] = 'Q';
            ca[j] = true;
            cb[i + j] = true;
            cc[n - 1 - (i - j)] = true;
            dfs(i + 1, n, table, ca, cb, cc);
            ca[j] = cb[i + j] = cc[n - 1 - (i - j)] = false;
            table[i][j] = '.';
        }
    }
}
