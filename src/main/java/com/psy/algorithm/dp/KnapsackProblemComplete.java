import FractionalKnapsackProblem.Item;

public class KnapsackProblemComplete {

    static int select(Item[] items, int total) {
        int[][] dp = new int[items.length][total + 1];
        Item item0 = items[0];
        for (int j = 0; j < total + 1; j++) {
            if (j >= item0.weight) {
                dp[0][j] = dp[0][j - item0.weight] + item0.value;
            }
        }
        for (int i = 1; i < items.length; i++) {
            Item item = items[i];
            for (int j = 0; j < total + 1; j++) {
                if (j >= item.weight) {
                    dp[i][j] = Integer.max(dp[i - 1][j], dp[i][j - item.weight] + item.value);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[items.length - 1][total];
    }

    static int select2(Item[] items, int total) {
        int[] dp = new int[total + 1];
        for (int i = 0; i < items.length; i++) {
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
