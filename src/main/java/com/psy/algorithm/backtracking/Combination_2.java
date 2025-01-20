import java.util.LinkedList;

public class Combination_2 {

    static List<List<Integer>> combinationSum3(int k, int target) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(1, n, k, new LinkedList<Integer>(), res);
        return res;
    }
    
    static int count = 0;
    static void dfs(int start, int target, int k, LinkedList<Integer> stack, List<List<Integer>> res) {
        count++;
        if (target == 0 && stack.size() == k) {
            res.add(new ArrayList<>(stack));
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (target < i) {
                continue;
            }
            if (stack.size() == k) {
                continue;
            }
            stack.push(i);
            dfs(i + 1, target - i, k, stack, res);
            stack.pop();
        }
    }
}
