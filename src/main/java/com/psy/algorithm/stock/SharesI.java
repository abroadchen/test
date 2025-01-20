public class SharesI {

    static int maxProfit(int[] prices) {
        int i = 0;
        int j = 1;
        int max = 0;
        while (j < prices.length) {
            if (prices[j] - prices[i] > 0) {
                max = Math.max(max, prices[j] - prices[i]);
                j++;
            } else {
                i = j;
                j++;
            }
        }
        return max;
    }
}
