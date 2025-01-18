import java.util.LinkedList;

public class TopologicalSort {

    private static void dfs(Vertex v, LinkedList<String> stack) {
        if (v.status == 2) {
            return;
        }
        if (v.status == 1) {
            throw new RuntimeException("Cycle detected");
        }
        v.status = 1;
        for (Edge edge: v.edges) {
            dfs(edge.linked, stack);
        }
        v.status = 2;
        stack.push(v.name);
    }
}
