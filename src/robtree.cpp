struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    map<TreeNode*, int> dp;
    int rob(TreeNode* root) {
        return dfs(root);
    }

private:
    int get_val(TreeNode* node) {
        if (node == NULL) return 0;
        else return dp[node];
    }

    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) {
            dp.emplace(root, root->val);
            return root->val;
        }
        int left_val = dfs(root->left);
        int right_val = dfs(root->right);
        int lower_vals = 0;
        if (root->left != NULL) lower_vals += get_val(root->left->left) + get_val(root->left->right);
        if (root->right != NULL) lower_vals += get_val(root->right->left) + get_val(root->right->right);
        int current_val;
        if (root->val + lower_vals > left_val + right_val) current_val = root->val + lower_vals;
        else current_val = left_val + right_val;
        dp.emplace(root, current_val);
        return current_val;
    }
};
