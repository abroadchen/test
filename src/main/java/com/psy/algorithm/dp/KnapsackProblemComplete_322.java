public class KnapsackProblemComplete_322 {

    static int coinChange(int[] coins, int amount) {
        int[][] dp = new int[coins.length][amount + 1];
        for (int j = 1; j < amount + 1; j++) {
            if (j >= coins[0]) {
                dp[0][j] = dp[0][j - coins[0]] + 1;
            } else {
                dp[0][j] = amount + 1;
            }
        }
        for (int i = 1; i < coins.length; i++) {
            for (int j = 1; j < amount + 1; j++) {
                if (j >= coins[i]) {
                    dp[i][j] = Integer.min(dp[i - 1][j], dp[i][j - coins[i]] + 1);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[coins.length - 1][amount] < amount + 1 ? dp[dp.length - 1][amount] : -1;
    }

    static int coinChange2(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1);
        dp[0] = 0;
        for (int coin: coins) {
            for (int j = coin; j < amount + 1; j++) {
                dp[j] = Integer.min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] < amount + 1 ? dp[amount] : -1;
    }
}
