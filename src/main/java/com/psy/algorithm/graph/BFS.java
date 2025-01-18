import java.util.LinkedList;

public class BFS {

    private static void bfs(Vertex v) {
        LinkedList<Vertex> queue = new LinkedList<>();
        queue.offer(v);
        v.visited = true;
        while (!queue.isEmpty()) {
            Vertex vertex = queue.poll();
            System.out.print(vertex.name + " ");
            for (Edge edge : vertex.edges) {
                if (!edge.linked.visited) {
                    queue.offer(edge.linked);
                    edge.linked.visited = true;
                }
            }
        }
    }
}
