package com.psy.algorithm.graph;
import java.util.List;

public class Vertex {

    String name;
    List<Edge> edges;

    boolean visited;
    int inDegree;
    int status;
    int dist = INF;
    static final Integer INF = Integer.MAX_VALUE;
    Vertex prev = null;

    public Vertex(String name) {
        this.name = name;
        edges = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return name + '(' + dist + ')';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Vertex vertex = (Vertex) o;
        return Objects.equals(name, vertex.name);
    }

    @Override
    public int hashCode() {
        return name != null ? name.hashCode() : 0;
    }
}
