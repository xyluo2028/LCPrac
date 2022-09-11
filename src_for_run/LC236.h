#include "common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = root;
        dfs(root, p, q);
        
        return ans;
    }
    
    bool dfs(TreeNode* root, TreeNode* target1, TreeNode* target2) {
        if (!root) return false;
        int left_ans = 0;
        int right_ans = 0;
        int mid_ans = 0;
        if (dfs(root->left, target1, target2)) {
            left_ans = 1;
        }
        if (dfs(root->right, target1, target2)) {
            right_ans = 1;
        }
        if (root->val == target1->val || root->val == target2->val) {
            mid_ans = 1;
        }
        if (right_ans + mid_ans + left_ans >= 2) {
            ans = root;
        }
        return (right_ans + mid_ans + left_ans) > 0;
    }
};