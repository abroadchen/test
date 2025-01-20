import java.util.LinkedList;

/*单调递减队列*/
public class MonotonicQueue {

    private LinkedList<Integer> deque = new LinkedList<>();

    public Integer peek() {
        return deque.peekFirst();
    }

    public void poll() {
        deque.pollFirst();
    }

    public void offer(Integer t) {
        while (!deque.isEmpty() && deque.peekLast() < t) {
            deque.pollLast();
        }
        deque.offerLast(t);
    }
}
