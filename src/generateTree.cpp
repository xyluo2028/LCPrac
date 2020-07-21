#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
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

private:
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

void dfs_print(TreeNode* root) {
    if (!root) return;
    cout << (root->val) << endl;
    dfs_print(root->left);
    dfs_print(root->right);
    return;
}

int main()
{
    Solution solve;
    vector<TreeNode*> result = solve.generateTrees(4);
    cout << result.size() << endl;
    dfs_print(result[3]);
}
