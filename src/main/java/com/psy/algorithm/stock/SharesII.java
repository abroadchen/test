public class SharesII {

    static int maxProfit(int[] prices) {
        int i = 0;
        int j = 1;
        int sum = 0;
        while (j < prices.length) {
            if (prices[j] - prices[i] > 0) {
                sum += prices[j] - prices[i];
            }
            i++;
            j++;
        }
        return sum;
    }
}
