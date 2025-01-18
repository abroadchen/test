import java.util.LinkedList;

public class DFS {


    private static void dfs(Vertex v) {
        v.visited = true;
        for (Edge edge: v.edges) {
            if (!edge.linked.visited) {
                dfs(edge.linked);
            }
        }
    }

    private static void dfs2(Vertex v) {
        LinkedList<Vertex> stack = new LinkedList<>();
        stack.push(v);
        while (!stack.isEmpty()) {
            Vertex current = stack.pop();
            current.visited = true;
            for (Edge edge: current.edges) {
                if (!edge.linked.visited) {
                    stack.push(edge.linked);
                }
            }
        }
    }
}
