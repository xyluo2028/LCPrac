/*
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
*/

#include "common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution95 {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> dp(n+2);
        TreeNode* tmp = new TreeNode(1);
        dp[1].push_back(tmp);
        if (n <= 1)return dp[n];
        stack<TreeNode*> tmpStack;
        for (size_t i = 2; i <= n; i++)
        {
            for (size_t j = 0; j < dp[i-1].size(); j++)
            {
                TreeNode* tmptree = deepCopyTree(dp[i - 1][j]);
                tmp = new TreeNode(i);
                tmp->left = tmptree;
                dp[i].push_back(tmp);
                dfs_insert(dp[i - 1][j], tmpStack, i);
                while (!tmpStack.empty())
                {
                    dp[i].push_back(tmpStack.top());
                    tmpStack.pop();
                }
            }
        }
        return dp[n];        
    }
    
    void dfs_insert(TreeNode* source, stack<TreeNode*>& container, int target) {
        TreeNode* tracer = source;
        int depth = 1;
        while (tracer->right != NULL) {
            tracer = tracer->right;
            depth++;
        }
        for (size_t i = 0; i < depth; i++)
        {
            TreeNode* tmp = deepCopyTree(source);
            tracer = tmp;
            for (size_t j = 0; j < i; j++) tracer = tracer->right;
            TreeNode* nodeIns = new TreeNode(target);
            nodeIns->left = tracer->right;
            tracer->right = nodeIns;
            container.push(tmp);
        }
        return;
    }

    TreeNode* deepCopyTree(TreeNode* source) {
        if (source == NULL) return NULL;
        TreeNode* head = new TreeNode(source->val);
        head->left = deepCopyTree(source->left);
        head->right = deepCopyTree(source->right);
        return head;
    }
};

/*
better solution: dp + recursive

class Solution {
public:
    vector<TreeNode*>helper(int st, int n, map<pair<int,int>,vector<TreeNode*>>&dp)
    {
        if(dp.find({st,n})!=dp.end())
            return dp[{st,n}];
        
        vector<TreeNode*>ans;
        if(st>n)
        {
            ans.push_back(NULL);
            return ans;
        }
        for(int i=st;i<=n;i++)
        {
            vector<TreeNode*>left = helper(st,i-1,dp);
            vector<TreeNode*>right = helper(i+1,n,dp);
            for(auto l:left)
            {
                for(auto r:right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->right = r;
                    root->left = l;
                    ans.push_back(root);
                }
            }
        }
        return dp[{st,n}] = ans;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int,int>,vector<TreeNode*>>dp;
        return helper(1,n,dp);
    }
};

*/