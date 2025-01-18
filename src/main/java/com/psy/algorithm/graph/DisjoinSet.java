public class DisjoinSet {


    int[] s;

    public DisjoinSet(int size) {
        s = new int[size];
        for (int i = 0; i < size; i++) {
            s[i] = i;
        }
    }

    public int find(int x) {
        if (x == s[x]) return x;
        return find(s[x]);
    }

    public void union(int x, int y) {
        s[y] = x;
    }
}
