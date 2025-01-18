import java.util.HashMap;

public class l1 {

    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int x = nums[i];
            int y = target - x;
            if (map.containsKey(y)) {
                return new int[]{map.get(y), i};
            } else {
                map.put(x, i);
            }
        }
        return null;
    }
}
