public class l235 {

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode a = root;
        while (p.val < a.val && q.val < a.val || a.val < p.val && a.val < q.val) {
            if (p.val < a.val) {
                a = a.left;
            } else {
                a = a.right;
            }
        }
        return a;
    }
}
