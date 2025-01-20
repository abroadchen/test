public class FindMedian {

    public static double findMedian(int[] nums) {
        if (nums.length % 2 == 1) {
            return QuickSelect.quick(nums, 0, nums.length - 1, nums.length / 2);
        } else {
            int x = QuickSelect.quick(nums, 0, nums.length - 1, nums.length / 2);
            int y = QuickSelect.quick(nums, 0, nums.length - 1, nums.length / 2 - 1);
            return (x + y) / 2.0;
        }
    }
}
