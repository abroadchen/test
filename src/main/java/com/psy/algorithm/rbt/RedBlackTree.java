public class RedBlackTree {

    enum Color {
        RED, BLACK
    }

    private Node root;

    private static class Node {
        int key;
        Object value;
        Node left, right;
        Node parent;
        Color color = RED;

        boolean isLeftChild() {
            return parent != null && parent.left == this;
        }

        Node uncle() {
            if (parent == null || parent.parent == null) {
                return null;
            }
            if (parent.isLeftChild()) {
                return parent.parent.right;
            } else {
                return parent.parent.left;
            }
        }

        Node sibling() {
            if (parent == null) {
                return null;
            }
            if (this.isLeftChild()) {
                return parent.right;
            } else {
                return parent.left;
            }
        }
    }
    
    boolean isRed(Node node) {
        return node != null && node.color == RED;
    }

    boolean isBlack(Node node) {
        return !isRed(node);
    }

    private void rightRotate(Node pink) {
        Node parent = pink.parent;
        Node yellow = pink.left;
        Node green = yellow.right;
        if (green != null) {
            green.parent = pink;
        }
        yellow.right = pink;
        yellow.parent = parent;
        pink.left = green;
        pink.parent = yellow;
        if (parent == null) {
            root = yellow;
        } else if (parent.left == pink) {
            parent.left = yellow;
        } else {
            parent.right = yellow;
        }
    }
    
    private void leftRotate(Node pink) {

    }

    public void put(int key, Object value) {
        Node p = root;
        Node parent = null;
        while (p != null) {
            parent = p;
            if (key == p.key) {
                p.value = value;
                return;
            } else if (key < p.key) {
                p = p.left;
            } else {
                p = p.right;
            }
        }
        Node inserted = new Node(key, value);
        if (parent == null) {
            root = inserted;
        } else if (key < parent.key) {
            parent.left = inserted;
            inserted.parent = parent;
        } else {
            parent.right = inserted;
            inserted.parent = parent;
        }
        fixRedRed(inserted);
    }

    void fixRedRed(Node x) {
        if (x == root) {
            x.color = BLACK;
            return;
        }
        if (isBlack(x.parent)) {
            return;
        }
        Node parent = x.parent;
        Node uncle = x.uncle();
        Node grandParent = parent.parent;
        if (isRed(uncle)) {
            parent.color = BLACK;
            uncle.color = BLACK;
            grandParent.color = RED;
            fixRedRed(grandParent);
            return;
        }
        if (parent.isLeftChild() && x.isLeftChild()) {
            parent.color = BLACK;
            grandParent.color = RED;
            rightRotate(grandParent);
        } else if (parent.isLeftChild()) {
            leftRotate(parent);
            x.color = BLACK;
            grandParent.color = RED;
            rightRotate(grandParent);
        } else if (!x.isLeftChild()) {
            parent.color = BLACK;
            grandParent.color = RED;
            leftRotate(grandParent);
        } else {
            rightRotate(parent);
            x.color = BLACK;
            grandParent.color = RED;
            leftRotate(grandParent);
        }
    }

    public void remove(int key) {
        Node deleted = find(key);
        if (deleted == null) {
            return;
        }
    }

    private void doRemove(Node deleted) {
        Node replaced = findReplaced(deleted);
        Node parent = deleted.parent;
        if (replaced == null) {
            if (deleted == root) {
                root = null;
            } else {
                if (isBlack(deleted)) {
                    fixDoubleBlack(deleted);
                } else {

                }
                if (deleted.isLeftChild()) {
                    parent.left = null;
                } else {
                    parent.right = null;
                }
                deleted.parent = null;
            }
            return;
        }
        if (deleted.left == null || deleted.right == null) {
            if (deleted == root) {
                root.key = replaced.key;
                root.value = replaced.value;
                root.left = root.right = null;
            } else {
                if (deleted.isLeftChild()) {
                    parent.left = replaced;
                } else {
                    parent.right = replaced;
                }
                replaced.parent = parent;
                deleted.parent = deleted.left = deleted.right = null;
                if (isBlack(deleted) && isBlack(replaced)) {
                    fixDoubleBlack(replaced);
                } else {
                    replaced.color = BLACK;
                }
            }
            return;
        }
        int t = deleted.key;
        deleted.key = replaced.key;
        replaced.key = t;
        Object v = deleted.value;
        deleted.value = replaced.value;
        replaced.value = v;
        doRemove(replaced);
    }

    private void fixDoubleBlack(Node x) {
        if (x == root) {
            return;
        }
        Node parent = x.parent;
        Node sibling = x.sibling();
        if (isRed(sibling)) {
            if (x.isLeftChild()) {
                leftRotate(parent);
            } else {
                rightRotate(parent);
            }
            parent.color = RED;
            sibling.color = BLACK;
            fixDoubleBlack(x);
            return;
        }
        if (sibling != null) {
            if (isBlack(sibling.left) && isBlack(sibling.right)) {
                sibling.color = RED;
                if (isRed(parent)) {
                    parent.color = BLACK;
                } else {
                    fixDoubleBlack(parent);
                }
            } else {
                if (sibling.isLeftChild() && isRed(sibling.left)) {
                    rightRotate(parent);
                    sibling.left.color = BLACK;
                    sibling.color = parent.color;
                } else if (sibling.isLeftChild() && isRed(sibling.right)) {
                    sibling.right.color = parent.color;
                    leftRotate(sibling);
                    rightRotate(parent);
                } else if (!sibling.isLeftChild() && isRed(sibling.right)) {
                    leftRotate(parent);
                    sibling.right.color = BLACK;
                    sibling.color = parent.color;
                } else {
                    sibling.left.color = parent.color;
                    rightRotate(sibling);
                    leftRotate(parent);
                }
                parent.color = BLACK;
            }
        } else {
            fixDoubleBlack(parent);
        }
    }



    private Node find(int key) {
        Node p = root;
        while (p != null) {
            if (key < p.key) {
                p = p.left;
            } else if (p.key < key) {
                p = p.right;
            } else {
                return p;
            }
        }
        return null;
    }

    pritate Node findReplaced(Node deleted) {
        if (deleted.left == null && deleted.right == null) {
            return null;
        }
        if (deleted.left == null) {
            return deleted.right;
        }
        if (deleted.right == null) {
            return deleted.left;
        }
        Node s = deleted.right;
        while (s.left != null) {
            s = s.left;
        }
        return s;
    }
}
