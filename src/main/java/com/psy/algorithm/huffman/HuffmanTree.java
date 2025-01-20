import java.util.PriorityQueue;

public class HuffmanTree {

    static claass Node {
        Character ch;
        int freq;
        Node left, right;
        String code;

        public Node(Character ch) {
            this.ch = ch;
        }

        public Node(int freq, Node left, Node right) {
            this.freq = freq;
            this.left = left;
            this.right = right;
        }

        int freq() {
            return freq;
        }

        boolean isLeaf() {
            return left == null;
        }

        @Override
        public String toString() {
            return Node{ch: ch, freq: freq};
        }
    }

    String str;
    Map<Character, Node> map = new HashMap<>();
    Node root;

    public HuffmanTree(String str) {
        this.str = str;
        char[] chars = str.toCharArray();
        for (char c : chars) {
            Node node = map.computeIfAbsent(c, Node::new);
            node.freq++;
        }
        PriorityQueue<Node> queue = new PriorityQueue<>(
            Comparator.comparingInt(Node::freq));
        );
        queue.addAll(map.values());
        while (queue.size() >= 2) {
            Node x = queue.poll();
            Node y = queue.poll();
            int freq = x.freq + y.freq;
            queue.offer(new Node(freq, x, y));
        }
        root = queue.poll();
        dfs(root, new StringBuilder());
    }

    private int dfs(Node node, StringBuilder code) {
        int sum = 0;
        if (node.isLeaf()) {
            node.code = code.toString();
            sum = node.freq * code.length();
        } else {
            sum += dfs(node.left, code.append('0'));
            sum += dfs(node.right, code.append('1'));
        }
        if (code.length() > 0) {
            code.deleteCharAt(code.length() - 1);
        }
        return sum;
    }

    public String encode() {
        char[] chars = str.toCharArray();
        StringBuilder sb = new StringBuilder();
        for (char c: chars) {
            sb.append(map.get(c).code);
        }
        return sb.toString();
    }

    public String decode(String str) {
        char[] chars = str.toCharArray();
        int i = 0;
        StringBuilder sb = new StringBuilder();
        Node node = root;
        while (i < chars.length) {
            if (!node.isLeaf()) {
                if (chars[i] == '0') {
                    node = node.left;
                } else if (chars[i] == '1') {
                    node = node.right;
                }
                i++;
            }
            if (node.isLeaf()) {
                sb.append(node.ch);
                node = root;
            }
        }
        return sb.toString();
    }
}
