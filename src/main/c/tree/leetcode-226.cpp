#include <cstddef>
using namespace std;

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == NULL) return NULL;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
