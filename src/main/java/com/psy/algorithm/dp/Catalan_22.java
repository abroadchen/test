public class Catalan_22 {

    static List<String> generateParenthesis(int n) {
        ArrayList<String>[] dp = new ArrayList[n + 1];
        dp[0] = new ArrayList<>(List.of(""));
        dp[1] = new ArrayList<>(List.of("()"));
        for (int i = 2; i <= n; i++) {
            dp[i] = new ArrayList<>();
            for (int j = 0; j < i; j++) {
                for (String k1: dp[j]) {
                    for (String k2: dp[i - j - 1]) {
                        dp[i].add("(" + k1 + ")" + k2);
                    }
                }
            }
        }
        return dp[n];
    }
}
