public class HouseRobber {


    public int rob(int[] houses) {
        int len = houses.length;
        if (len == 1) {
            return houses[0];
        }
        int[] dp = new int[len];
        for (int i = 0; i < len; i++) {
            if (i == 0) {
                dp[i] = houses[i];
            } else if (i == 1) {
                dp[i] = Integer.max(houses[i], houses[i - 1]);
            } else {
                dp[i] = Integer.max(dp[i - 1], dp[i - 2] + houses[i]);
            }
        }
        return dp[len - 1];
    }
}
