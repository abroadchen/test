public class CutRodProblem {

    static int cut(int[] values, int n) {
        int[][] dp = new int[values.length][n + 1];
        for (int i = 1; i < values.length; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (j >= i) {
                    dp[i][j] = Integer.max(dp[i - 1][j], values[i] + dp[i][j - i]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[values.length - 1][n];
    }

}
