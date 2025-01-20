import java.util.Random;

public class SkipList {

    static Random r = new Random();
    static int randomLevel(int max) {
        int x = 1;
        while (x < max) {
            if (r.nextBoolean()) {
                return x;
            }
            x++;
        }
        return x;
    }

    static class Skiplist {
        private static final int MAX = 10;
        private final Node head = new Node(-1);

        static class Node {
            int val;
            Node[] next = new Node[MAX];//redis 32 java 62
            public Node(int val) {
                this.val = val;
            }
        }

        public Node[] find(int val) {
            Node[] path = new Node[MAX];
            Node curr = head;
            for (int level = MAX - 1; level >= 0; level--) {
                while (curr.next[level] != null && curr.next[level].val < val) {
                    curr = curr.next[level];
                }
                path[level] = curr;
            }
            return path;
        }



        public boolean search(int val) {
            Node[] path = find(val);
            Node node = path[0].next[0];
            return node != null && node.val == val;
        }

        public void add(int val) {
            Node[] path = find(val);
            Node node = new Node(val);
            int level = randomLevel(MAX);
            for (int i = 0; i < level; i++) {
                node.next[i] = path[i].next[i];
                path[i].next[i] = node;
            }
        }

        public boolean erase(int val) {
            Node[] path = find(val);
            Node node = path[0].next[0];
            if (node == null || node.val != val) {
                return false;
            }
            for (int i = 0; i < MAX; i++) {
                if (path[i].next[i] != node) {
                    break;
                }
                path[i].next[i] = node.next[i];
            }
            return true;
        }
    }
}
