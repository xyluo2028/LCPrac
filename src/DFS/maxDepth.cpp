struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return dfs(root);
    }

private:
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int leftH = dfs(root->left);
        int rightH = dfs(root->right);
        return ((leftH > rightH) ? leftH : rightH) + 1;

    }
};
