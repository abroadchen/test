import java.util.Arrays;

public class BTree {

    static class Node {
        int[] keys;
        Node[] children;
        int keyNumber;//有效关键字数
        boolean leaf = true;
        int t;//最小度数
        
        public Node(int t) {
            this.t = t;
            this.keys = new int[2 * t - 1];
            this.children = new Node[2 * t];
        }

        @Override
        public String toString() {
            return Arrays.toString(Arrays.copyOfRange(keys, 0, keyNumber));
        }

        Node get(int key) {
            int i = 0;
            while (i < keyNumber) {
                if (keys[i] == key) {
                    return this;
                }
                if (keys[i] > key) {
                    break;
                }
                i++;
            }
            if (leaf) {
                return null;
            }
            return children[i].get(key);
        }

        void insertKey(int key, int index) {
            System.arraycopy(keys, index, keys, index + 1, keyNumber - index);
            keys[index] = key;
            keyNumber++;
        }

        void insertChild(Node child, int index) {
            System.arraycopy(children, index, children, index + 1, keyNumber - index);
            children[index] = child;
        }

        int removeKey(int index) {
            int t = keys[index];
            System.arraycopy(keys, index + 1, keys, index, --keyNumber - index);
            return t;
        }

        int removeLeftmostKey() {
            return removeKey(0);
        }

        int removeRightmostKey() {
            return removeKey(keyNumber - 1);
        }

        Node removeChild(int index) {
            Node t = children[index];
            System.arraycopy(children, index + 1, children, index, keyNumber - index);
            children[--keyNumber] = null;
            return t;
        }

        Node removeLeftmostChild() {
            return removeChild(0);
        }

        Node removeRightmostChild() {
            return removeChild(keyNumber);
        }

        Node childLeftSibling(int index) {
            return index > 0 ? children[index - 1] : null;
        }

        Node childRightSibling(int index) {
            return index == keyNumber ? null : children[index + 1];
        }

        void moveToTarget(Node target) {
            int start = target.keyNumber;
            if (!leaf) {
                for (int i = 0; i <= keyNumber; i++) {
                    target.children[start + i] = children[i];
                }
            }
            for (int i = 0; i < keyNumber; i++) {
                target.keys[target.keyNumber++] = keys[i];
            }
        }
    }

    Node root;

    int t;
    final int MIN_KEY_NUMBER;
    final int MAX_KEY_NUMBER;

    public BTree() {
        this(2);
    }

    public BTree(int t) {
        this.t = t;
        root = new Node(t);
        MAX_KEY_NUMBER = 2 * t - 1;
        MIN_KEY_NUMBER = t - 1;
    }

    public boolean contains(int key) {
        return root.get(key) != null;
    }

    public void put(int key) {
        doPut(root, key, null, 0);
    }

    private void doPut(Node node, int key, Node parent, int index) {
        int i = 0;
        while (i < node.keyNumber) {
            if (node.keys[i] == key) {
                return;
            }
            if (node.keys[i] > key) {
                break;
            }
            i++;
        }
        if (node.leaf) {
            node.insertKey(key, i);
        } else {
            doPut(node.children[i], key, node, i);
        }
        if (node.keyNumber == MAX_KEY_NUMBER) {
            split(node, parent, index);
        }
    }

    private void split(Node left, Node parent, int index) {
        if (parent == null) {
            Node newRoot = new Node(t);
            newRoot.leaf = false;
            newRoot.insertChild(left, 0);
            this.root = newRoot;
            parent = newRoot;
        }
        Node right = new Node(t);
        right.leaf = left.leaf;
        System.arraycopy(left.keys, t, right.keys, 0, t - 1);
        if (!left.leaf) {
            System.arraycopy(left.children, t, right.children, 0, t);
        }
        right.keyNumber = t - 1;
        left.keyNumber = t - 1;
        int mid = left.keys[t - 1];
        parent.insertKey(mid, index);
        parent.insertChild(right, index + 1);
    }


    public void remove(int key) {
        doRemove(null, root, 0, key);
    }

    private void doRemove(Node parent, Node node, int index, int key) {
        int i = 0;
        while (i < node.keyNumber) {
            if (node.keys[i] >= key) {
                break;
            }
            i++;
        }
        if (node.leaf) {
            if (!found(node, key, i)) {
                return;
            } else {
                node.removeKey(i);
            }
        } else {
            if (!found(node, key, i)) {
                doRemove(node, node.children[i], i, key);
            } else {
                Node s = node.children[i + 1];
                while (!s.leaf) {
                    s = s.children[0];
                }
                int skey = s.keys[0];
                node.keys[i] = skey;
                doRemove(node, node.children[i + 1], i + 1, skey);
            }
        }
        if (node.keyNumber < MIN_KEY_NUMBER) {
            balance(parent, node, index);
        }
    }

    private void balance(Node parent, Node x, int i) {
        if (x == root) {
            if (root.keyNumber == 0 && root.children[0] != null) {
                root = root.children[0];
            }
            return;
        }
        Node left = parent.childLeftSibling(i);
        Node right = parent.childRightSibling(i);
        if (left != null && left.keyNumber > MIN_KEY_NUMBER) {
            x.insertKey(parent.keys[i - 1], 0);
            parent.keys[i - 1] = left.removeRightmostKey();
            if (!left.leaf) {
                x.insertChild(left.removeRightmostChild(), 0);
            }
            return;
        }
        if (right != null && right.keyNumber > MIN_KEY_NUMBER) {
            x.insertKey(parent.keys[i], x.keyNumber);
            if (!right.leaf) {
                x.insertChild(right.removeLeftmostChild(), x.keyNumber + 1);
            }
            parent.keys[i] = right.removeLeftmostKey();
            return;
        }
        if (left != null) {
            parent.removeChild(i);
            left.insertKey(parent.removeKey(i - 1), left.keyNumber);
            x.moveToTarget(left);
        } else {
            parent.removeChild(i + 1);
            x.insertKey(parent.removeKey(i), x.keyNumber);
            right.moveToTarget(x);
        }
    }

    private boolean found(Node node, int key, int i) {
        return i < node.keyNumber && node.keys[i] == key;
    }
}
