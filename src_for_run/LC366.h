#include "common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution366 {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        while (root != nullptr) {
            vector<int> leaves;
            dfs(root, leaves);
            ans.push_back(leaves);
            //cout << "leaves: " << leaves.size() << endl;
            if (root->val > 100) {
                break;
            }
        } 
        return ans;
    }
    
    void dfs(TreeNode* root, vector<int>& leaves) {
        //cout << root->val << endl;
        if (!root) return;
        if (root->left == nullptr && root->right == nullptr) {
            leaves.push_back(root->val);
            root->val = 101;
            return;
        }
        //cout << "debug" << endl;
        
        if (root->left != nullptr) dfs(root->left, leaves);
        if (root->left && root->left->val > 100) {
            delete root->left;
            root->left = nullptr;
        }
        if (root->right != nullptr) dfs(root->right, leaves);
        if (root->right && root->right->val > 100) {
            delete root->right;
            root->right = nullptr;
        }
    }
};

class Solution366A {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        ans.clear();
        dfs_with_height(root);
        return ans;
    }
    
    int dfs_with_height(TreeNode* root) {
        if (!root) return -1;
        int leftH = dfs_with_height(root->left);
        int rightH = dfs_with_height(root->right);
        int curH = max(leftH, rightH) + 1;
        if (ans.size() == curH) {
            ans.push_back({});
        }
        ans[curH].push_back(root->val);
        return curH;
    }
private:
    vector<vector<int>> ans;
};