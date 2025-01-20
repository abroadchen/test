import java.util.LinkedList;

public class Combination_1 {

    static List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(0, candidates, target, new LinkedList<>(), res);
        return res;
    }

    static void dfs(int start, int[] candidates, int target, LinkedList<Integer> stack, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<>(stack));
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            int candidate = candidates[i];
            if (target < candidate) {
                continue;
            }
            stack.push(candidate);
            dfs(i, candidates, target - candidate, stack, res);
            stack.pop();
        }
    }
}
