import java.util.LinkedList;

public class Combination_1_1 {

    static List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(candidates);
        dfs(0, candidates, new boolean[candidates.length], target, new LinkedList<>(), res);
        return res;
    }

    static void dfs(int start, int[] candidates, boolean[] visited, int target, LinkedList<Integer> stack, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<>(stack));
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            int candidate = candidates[i];
            if (target < candidate) {
                continue;
            }
            if (i > 0 && candidate == candidates[i - 1] && !visited[i - 1]) {
                continue;
            }
            visited[i] = true;
            stack.push(candidate);
            dfs(i + 1, candidates, visited, target - candidate, stack, res);
            stack.pop();
            visited[i] = false;
        }
    }
}
