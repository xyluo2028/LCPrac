// Binary Tree Cameras
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
    int ans = 0;
    enum state { HAS_CAMERA, COVERED, PLEASE_COVER };
    int minCameraCover(TreeNode* root) {
        return dfs(root) == PLEASE_COVER ? ++ans : ans;
    }
    
    state dfs(TreeNode* root) {
        if (!root) return COVERED;
        state left_state = dfs(root->left);
        state right_state = dfs(root->right);
        if (left_state == PLEASE_COVER || right_state == PLEASE_COVER){
            ++ans;
            return HAS_CAMERA;
        }
        if (left_state == HAS_CAMERA || right_state == HAS_CAMERA) {
            return COVERED;
        }
        return PLEASE_COVER;
        
    }
};