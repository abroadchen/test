import java.util.LinkedList;
import java.util.concurrent.atomic.AtomicInteger;

public class l322 {

    static int min = -1;
    public int coinChange(int[] coins, int amount) {
        rec(0, coins, amount, new LinkedList<>(), true);
        return min;
    }

    public int rec(int index, int[] coins, int remainder, AtomicInteger count, LinkedList<Integer> stack, boolean first) {
        if (!first) {
            stack.push(coins[index]);
        }
        count.incrementAndGet();
        if (remainder == 0) {
            if (min == -1) {
                min = count.get();
            } else {
                min = Integer.min(min, count.get());
            }
        } else if (remainder > 0) {
            for (int i = index; i < coins.length; i++) {
                count += rec(i, coins, remainder - coins[i], count, stack, false);
            }
        }
        count.decrementAndGet();
        if (!stack.isEmpty()) {
            stack.pop();
        }
        return count;
    }
}
