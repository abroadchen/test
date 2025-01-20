public class TravellingSalesmanProblem {

    static int tsp(int[][] g) {
        int m = g.length;
        int n = 1 << (m - 1);
        int[][] dp = new int[m][n];
        for (int k = 0; k < m; k++) {
            dp[k][0] = g[k][0];
        }
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < m; i++) {
                dp[i][j] = Integer.MAX_VALUE >>> 1;
                if (contains(j, i)) continue;
                for (int k = 0; k < m; k++) {
                    if (contains(j, k)) {
                        dp[i][j] = Integer.min(dp[i][j], dp[k][exclude(j, k)] + g[i][k]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }

    static boolean contains(int set, int city) {
        return (set >> (city - 1) & 1) == 1;
    }

    static int exclude(int set, int city) {
        return set ^ (1 << (city - 1));
    }
}
