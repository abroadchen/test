import java.util.PriorityQueue;

public class Kruskal {

    static void Kruskal(int size, PriorityQueue<Edge> queue) {
        List<Edge> list = new ArrayList<>();
        DisjointSet set = new DisjointSet(size);
        while (list.size() < size - 1) {
            Edge poll = queue.poll();
            int i = set.find(poll.start);
            int j = set.find(poll.end);
            if (i != j) {
                list.add(poll);
                set.union(i, j);
            }
        }
    }




    static class Edge implements Comparable<Edge> {
        List<Vertex> vertices;
        int start;
        int end;
        int weight;

        public Edge(List<Vertex> vertices, int start, int end, int weight) {
            this.start = start;
            this.end = end;
            this.weight = weight;
            this.vertices = vertices;
        }

        public Edge(int start, int end, int weight) {
            this.start = start;
            this.end = end;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.weight, o.weight);
        }

        @Override
        public String toString() {
            return "Edge{" +
                    "start=" + start +
                    ", end=" + end +
                    ", weight=" + weight +
                    '}';
        }
    }
}
