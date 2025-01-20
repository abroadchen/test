package com.psy.algorithm.graph;

public class BellmanFord {

    public static void main(String[] args) {
        int[] dp = new int[7];
        dp[1] = 0;
        for (int i = 2; i < dp.length; i++) {
            dp[i] = Integer.MAX_VALUE;
        }
        for (int i = 0; i < 5; i++) {
            for (Edge e: edges) {
                if (dp[e.from] != Integer.MAX_VALUE) {
                    dp[e.to] = Integer.min(dp[e.to], dp[e.from] + e.weight);
                }
            }
        }
    }
}
