public class FloydWarshall {

    static void FloydWarshall(List<Vertex> graph) {
        int size = graph.size();
        int[][] dist = new int[size][size];
        Vertex[][] prev = new Vertex[size][size];
        for (int i = 0; i < size; i++) {
            Vertex v = graph.get(i);
            Map<Vertex, Integer> edges = v.edges.stream().collect(Collectors.toMap(e -> e.linked, e -> e.weight));
            for (int j = 0; j < size; j++) {
                Vertex u = graph.get(j);
                if (v == u) {
                    dist[i][j] = 0;
                } else {
                    dist[i][j] = edges.getOrDefault(u, Integer.MAX_VALUE);
                    prev[i][j] = map.get(u) != null ? v : null;
                }
            }
            for (int k = 0; k < size; k++) {
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        //i行的顶点 借助k顶点 到达j列顶点
                        if (dist[i][k] != Integer.MAX_VALUE 
                            && dist[k][j] != Integer.MAX_VALUE 
                            && dist[i][k] + dist[k][j] < dist[i][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                            prev[i][j] = prev[k][j];
                        }
                    }
                }
            }
            //对角线出现负值 出现负环
        }
    }
}
