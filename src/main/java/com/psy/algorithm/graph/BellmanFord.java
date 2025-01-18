package com.psy.algorithm.graph;

import com.psy.algorithm.graph.Vertex;

public class BellmanFord {


    private static void BellmanFord(List<Vertex> graph, Vertex source) {
        source.dist = 0;
        int size = graph.size();
        for (int i = 0; i < size - 1; i++) {
            for (Vertex s: graph) {
                for (Edge edge: s.edges) {
                    Vertex e = edge.linked;
                    if (s.dist != Integer.MAX_VALUE && s.dist + edge.weight < e.dist) {
                        e.dist = s.dist + edge.weight;
                        e.prev = s;
                    }
                }
            }
        }
    }
}
