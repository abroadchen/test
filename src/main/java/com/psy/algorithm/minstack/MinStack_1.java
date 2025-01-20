import java.util.LinkedList;

public class MinStack_1 {

    static class MinStack {

        record Data(int val, int min) {}

        LinkedList<Data> stack = new LinkedList<>();

        public void push(int val) {
            if (stack.isEmpty()) {
                stack.push(new Data(val, val));
            } else {
                stack.push(new Data(val, Math.min(stack.peek().min, val)));
            }
        }

        public void pop() {
            stack.pop();
        }

        public int top() {
            return stack.peek().val;
        }

        public int getMin() {
            return stack.peek().min;
        }
    }
}
