#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;
        if (dfs(root, head)) return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
        
    }
    
    bool dfs(TreeNode* tNode, ListNode* lNode) {
        if (!lNode) return true;
        if (!tNode) return false;
        if (tNode->val != lNode->val) return false;
        return dfs(tNode->left, lNode->next) || dfs(tNode->right, lNode->next);
        
    }
    
    ListNode* head_org;
};