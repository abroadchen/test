import java.util.LinkedList;

public class TrappingRainWater {

    static int trap(int[] height) {
        LinkedList<Data> stack = new LinkedList<>();
        int sum = 0;
        for (int i = 0; i < height.length; i++) {
            Data right = new Data(height[i], i);
            while (!stack.isEmpty() && stack.peek().height < right.height) {
                Data pop = stack.pop();
                Data left = stack.peek();
                if (left != null) {
                    int width = right.i - left.i - 1;
                    int height = Math.min(left.height, right.height) - pop.height;
                    sum += width * height;
                }
            }
            stack.push(right);
        }
        return sum;
    }

    static class Data {
        int height;
        int i;

        public Data(int height, int i) {
            this.height = height;
            this.i = i;
        }

        @Override
        public String toString() {
            return String.valueOf(height);
        }
    }
}
