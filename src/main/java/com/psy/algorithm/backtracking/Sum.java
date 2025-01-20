import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;

public class Sum {

    static public int[] twoSum(int[] numbers, int target) {
        int i = 0;
        int j = numbers.length - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                break;
            }
        }
        return new int[] { i + 1, j + 1 };
    }

    static List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new LinkedList<>();
        dfs(3, 0, nums.length - 1, 0, nums, new LinkedList<>(), res);
        return res;
    }

    static void dfs(int n, int i, int j, int target, int[] nums, List<Integer> stack, List<List<Integer>> res) {
        if (n == 2) {
            twoSum(i, j, numbers, target, stack, res);
            return;
        }
        for (int k = i; k < j - (n - 2); k++) {
            if (k > i && nums[k] == nums[k - 1]) {
                continue;
            }
            stack.push(nums[k]);
            dfs(n - 1, k + 1, j, target - nums[k], nums, stack, res);
            stack.pop();
        }
    }

    static public void twoSum(int i, int j, int[] numbers, int target, List<Integer> stack, List<List<Integer>> res) {
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                ArrayList<Integer> list = new ArrayList<>();
                list.add(numbers[i]);
                list.add(numbers[j]);
                res.add(list);
                i++;
                j--;
                while (i < j && numbers[i] == numbers[i - 1]) {
                    i++;
                }
                while (i < j && numbers[j] == numbers[j + 1]) {
                    j--;
                }
            }
        }
    }


    static List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> res = new LinkedList<>();
        dfs(4, 0, nums.length - 1, 0, nums, new LinkedList<>(), res);
        return res;
    }
}
