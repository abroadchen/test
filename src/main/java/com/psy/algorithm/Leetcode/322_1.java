public class l322_1 {

    public int coinChange(int[] coins, int amount) {
        int remaider = amount;
        int count = 0;
        for (int coin: coins) {
            while (remaider > coin) {
                remaider -= coin;
                count++;
            }
            if (remaider == coin) {
                remaider = 0;
                count++;
                break;
            }
        }
        if (remaider > 0) {
            return -1;
        } else {
            return count;
        }
    }

}
