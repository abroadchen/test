public class DisjoinSet {


    int[] s;
    int[] size;

    public DisjoinSet(int size) {
        s = new int[size];
        this.size = new int[size];
        for (int i = 0; i < size; i++) {
            s[i] = i;
            this.size[i] = 1;
        }
    }

    public int find(int x) {
        if (x == s[x]) return x;
        return s[x] = find(s[x]);
    }

    public void union(int x, int y) {
        if (size[x] < size[y]) {
            int t = x;
            x = y;
            y = t;
        }
        s[y] = x;
        size[x] += size[y];
    }
}
