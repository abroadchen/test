import java.util.LinkedList;

public class Permute_1 {

    static List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(nums, new boolean[nums.length], new LinkedList<>(), res);
    }

    static void dfs(int[] nums, boolean[] visited, LinkedList<Integer> stack, List<List<Integer>> res) {
        if (stack.size() == nums.length) {
            res.add(new ArrayList<>(stack));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }
            if (!visited[i]) {
                visited[i] = true;
                stack.push(nums[i]);
                dfs(nums, visited, stack, res);
                stack.pop();
                visited[i] = false;
            }
        }
    }
}
