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
    vector<int> ans;
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        ans.clear();
        ans.push_back(root->val);
        addLeft(root->left, true);
        addRight(root->right, true);
        return ans;
    }
    
    void addLeft(TreeNode* node, bool isBoundary) {
        if (!node) return;
        bool isL = isLeaf(node);
        if (isBoundary || isL) ans.push_back(node->val);
        if (!isL) {
            addLeft(node->left, isBoundary);
            addLeft(node->right, isBoundary && !node->left);
        }
    }
    
    void addRight(TreeNode* node, bool isBoundary) {
        if (!node) return;
        bool isL = isLeaf(node);
        if (!isL) {
            addRight(node->left, isBoundary && !node->right);
            addRight(node->right, isBoundary);
        }
        if (isBoundary || isL) ans.push_back(node->val);
    }
    
    bool isLeaf(TreeNode* node) {
        return (!node->left) && (!node->right);
    }
};

class SolutionLeftLeafRight {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        ans.push_back(root->val);
        if (isLeaf(root)) return ans;
        if (root->left) solveLeft(root->left, ans);
        solveLeaves(root, ans);
        if (root->right) solveRight(root->right, ans);
        return ans;
    }
    
    void solveLeft(TreeNode* node, vector<int>& leftNs) {
        if (isLeaf(node)) return;
        leftNs.push_back(node->val);
        if (node->left) solveLeft(node->left, leftNs);
        else if (node->right) solveLeft(node->right, leftNs);
    }
    
    void solveRight(TreeNode* node, vector<int>& rightNs) {
        if (isLeaf(node)) return;
        if (node->right) solveRight(node->right, rightNs);
        else if (node->left) solveRight(node->left, rightNs);
        rightNs.push_back(node->val);
        
    }
    
    void solveLeaves(TreeNode* node, vector<int>& leaves) {
        if (isLeaf(node)) {
            leaves.push_back(node->val);
            return;
        }
        if (node->left) solveLeaves(node->left, leaves);
        if (node->right) solveLeaves(node->right, leaves);
    }
    
    bool isLeaf(TreeNode* root) {
        return (!root->left) && (!root->right);
    }
};