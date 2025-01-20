public class KnapsackProblem {

    static int select(Item[] items, int total) {
        int[][] dp = new int[items.length][total + 1];
        Item item0 = items[0];
        for (int j = 0; j < total + 1; j++) {
            dp[0][j] = j >= item0.weight ? item0.value : 0;
        }
        for (int i = 1; i < dp.length; i++) {
            Item item = items[i];
            for (int j = 0; j < total + 1; j++) {
                if (j >= item.weight) {
                    dp[i][j] = Integer.max(dp[i - 1][j], dp[i - 1][j - item.weight] + item.value);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[items.length - 1][total];
    }

    static int select2(Item[] items, int total) {
        int[] dp = new int[total + 1];
        Item item0 = items[0];
        for (int j = 0; j < total + 1; j++) {
            dp[j] = j >= item0.weight ? item0.value : 0;
        }
        for (int i = 1; i < items.length; i++) {
            Item item = items[i];
            for (int j = total; j > 0; j--) {
                if (j >= item.weight) {
                    dp[j] = Integer.max(dp[j], dp[j - item.weight] + item.value);
                }
            }
        }
        return dp[total];
    }
}
