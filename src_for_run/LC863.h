#include "common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> ans;
    TreeNode* m_target;
    int m_k;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        m_target = target;
        m_k = k;
        ans.clear();
        dfs_target(root);
        return ans;
    }
    
    int dfs_target(TreeNode* node) {
        if (!node) return -1;
        if (node == m_target) {
            dfs_depth(node, 0, m_k);
            return 0;
        }
        int left_depth = dfs_target(node->left);
        int right_depth = dfs_target(node->right);
        int tmp_ans = -1;
        if (left_depth >= 0) {
            tmp_ans = left_depth + 1;
            if (tmp_ans == m_k) {
                ans.push_back(node->val);
            }
            if (tmp_ans < m_k) {
                dfs_depth(node->right, 1, m_k - tmp_ans);
            }
        }
        if (right_depth >= 0) {
            tmp_ans = right_depth + 1;
            if (tmp_ans == m_k) {
                ans.push_back(node->val);
            }
            if (tmp_ans < m_k) {
                dfs_depth(node->left, 1, m_k - tmp_ans);
            }
        }
        return tmp_ans;
    }
    
    void dfs_depth(TreeNode* node, int curr_depth, int target_depth) {
        if (!node) return;
        if (curr_depth == target_depth) {
            ans.push_back(node->val);
            return;
        }
        dfs_depth(node->left, curr_depth + 1, target_depth);
        dfs_depth(node->right, curr_depth + 1, target_depth);
    }
    
};