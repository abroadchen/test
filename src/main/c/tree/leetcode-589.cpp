#include <cstddef>
#include <vector>
using namespace std;
class Solution {
public:

    void __preorder(Node *root, vector<int> &ans) {
        if (root == NULL) return vector<int>();
        ans.push_back(root->val);
        for (auto x: root->children) {
            __preorder(x, ans);
        }
        return;
    }

    vector<int> preorder(Node *root) {
        vector<int> ans;
        __preorder(root, ans);
        return ans;
    }
}
