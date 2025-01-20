import java.util.Arrays;

public class SharesIII_1 {

    static int maxProfit(int k, int[] prices) {
        //int buy1 = Integer.MIN_VALUE;
        //int sell1 = 0;
        //int buy2 = Integer.MIN_VALUE;
        //int sell2 = 0;
        //int buy3 = Integer.MIN_VALUE;
        //int sell3 = 0;
        if (k > prices.length / 2) {
            return SharesII::maxProfit(prices);
        }
        int[] buy = new int[k];
        int[] sell = new int[k];
        Arrays.fill(buy, Integer.MIN_VALUE);
        for (int price: prices) {
            buy[0] = Math.max(buy[0], -price);
            sell[0] = Math.max(sell[0], buy[0] + price);
            //buy2 = Math.max(buy2, sell1 - price);
            //sell2 = Math.max(sell2, buy2 + price);
            //buy3 = Math.max(buy3, sell2 - price);
            //sell3 = Math.max(sell3, buy3 + price);

            for (int i = 1; i < k; i++) {
                buy[i] = Math.max(buy[i], sell[i - 1] - price);
                sell[i] = Math.max(sell[i], buy[i] + price);
            }
        }
        return sell[k - 1];
    }
}
