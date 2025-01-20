import java.util.LinkedList;

public class l518 {

    public int coinChange(int[] coins, int amount) {
        return rec(0, coins, amount, new LinkedList<>(), true);
    }

    public int rec(int index, int[] coins, int remainder, LinkedList<Integer> stack, boolean first) {
        if (!first) {
            stack.push(coins[index]);
        }
        int count = 0;
        if (remainder < 0) {
            print("无解", stack);
        } else if (remainder == 0) {
            count = 1;
        } else {
            for (int i = index; i < coins.length; i++) {
                count += rec(i, coins, remainder - coins[i], stack, false);
            }
        }
        if (!stack.isEmpty()) {
            stack.pop();
        }
        return count;
    }
}
