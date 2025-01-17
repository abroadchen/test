public class l1008 {

    public TreeNode bstFromPreorder(int[] preorder) {
        return partition(preorder, 0, preorder.length - 1);
    }
    int i = 0;
    private TreeNode partition(int[] preoder, int start, int end) {
        if (start > end) {
            return null;
        }
        TreeNode root = new TreeNode(preoder[start]);
        int index = start + 1;
        while (index <= end) {
            if (preoder[index] > preoder[start]) {
                break;
            }
            inde++;
        }
        root.left = partition(preoder, start + 1, index - 1);
        root.right = partition(preoder, index, end);
        return root;
    }
}
