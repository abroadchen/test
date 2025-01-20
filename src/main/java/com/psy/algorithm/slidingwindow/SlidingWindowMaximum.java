import java.awt.List;
import java.util.ArrayList;

public class SlidingWindowMaximum {

    static int[] maxSlidingWindow(int[] nums, int k) {
        MonotonicQueue queue = new MonotonicQueue();
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (i >= k && queue.peek() == nums[i - k]) {
                queue.poll();
            }
            int num = nums[i];
            queue.offer(num);
            if (i >= (k - 1)) {
                list.add(queue.peek());
            }
        }
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}
