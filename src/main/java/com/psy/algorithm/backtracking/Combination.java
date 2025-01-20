import java.util.LinkedList;

public class Combination {

    static List<List<Integer>> Combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(1, n, k, new LinkedList<Integer>(), res);
        return res;
    }

    static void dfs(int start, int n, int k, LinkedList<Integer> stack, List<List<Integer>> res) {
        if (stack.size() == k) {
            res.add(new ArrayList<>(stack));
            return;
        }
        for (int i = start; i <= n; i++) {
            if (k - stack.size() > n - i + 1) {
                continue;
            }
            stack.push(i);
            dfs(i + 1, n, k, stack, res);
            stack.pop();
        }
    }
}
