#include "common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution114 {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        
        queue<TreeNode*> rightnodes;
        dfs(root, rightnodes);
        root = rightnodes.front();
        TreeNode* tracer = root;
        while (!rightnodes.empty())
        {
            rightnodes.pop();
            if (rightnodes.empty()) break;
            tracer->left = nullptr;
            tracer->right = rightnodes.front();
            tracer = tracer->right;
        }
        tracer->left = nullptr;
        tracer->right = nullptr;
        return;
    }

private:
    void dfs(TreeNode* root,  queue<TreeNode*>& rightnodes) {  // preorder dfs push all treenode ptr to a queue
        if (root == NULL) return;
        rightnodes.push(root);
        dfs(root->left, rightnodes);
        dfs(root->right, rightnodes);
        return;
    }
};


/*
solution without queue or other containers, 
use "morries traverse"

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* cur = root;
        while(cur){
            if(cur->left) {
                TreeNode* pred = cur->left;
                while(pred->right)
                    pred = pred->right;
                pred->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};
*/