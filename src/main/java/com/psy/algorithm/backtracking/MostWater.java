
public class MostWater {

    static int maxArea(int[] height) {
        int i = 0;
        int j = height.length - 1;
        int max = 0;
        while (i < j) {
            if (height[i] < height[j]) {
                int area = (j - i) * height[i];
                max = Math.max(max, area);
                i++;
            } else {
                int area = (j - i) * height[j];
                max = Math.max(max, area);
                j--;
            }
        }
        return max;
    }
}
