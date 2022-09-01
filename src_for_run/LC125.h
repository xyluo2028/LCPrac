#include "common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxNum;
    int maxPathSum(TreeNode* root) {
        maxNum = -99999;
        int ans = maxGain(root);
        return maxNum;
    }

    int maxGain(TreeNode* root){
        if(!root) return 0;
        int leftGain = max(0, maxGain(root->left));
        int rightGain = max(0, maxGain(root->right));
        int newPath = root->val;
        //update maxNum
        newPath += leftGain;
        newPath += rightGain;
        maxNum = maxNum > newPath ? maxNum : newPath;
        return root->val + max(leftGain, rightGain);
    }
};