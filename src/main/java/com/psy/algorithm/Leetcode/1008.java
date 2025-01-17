public class l1008 {

    public TreeNode bstFromPreorder(int[] preorder) {
        return insert(preorder, Integer.MAX_VALUE);
    }
    int i = 0;
    private TreeNode insert(int[] preoder, int max) {
        if (i == preoder.length) {
            return null;
        }
        int val = preoder[i];
        if (val > max) {
            return null;
        }
        TreeNode node = new TreeNode(val);
        i++;
        node.left = insert(preoder, val);
        node.right = insert(preoder, max);
        return node;
    }
}
