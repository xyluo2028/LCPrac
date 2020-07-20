#include <iostream>
#include <queue>

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

    void flatten(TreeNode* root) {
        if (!root) return;
        
        queue<TreeNode*> rightnodes;
        dfs(root, rightnodes);
        root = rightnodes.front();
        TreeNode* tracer = root;
        while (!rightnodes.empty())
        {
            cout << tracer->val << endl;
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
    void dfs(TreeNode* root,  queue<TreeNode*>& rightnodes) {
        if (root == NULL) return;
        rightnodes.push(root);
        //cout << root->val << endl;
        dfs(root->left, rightnodes);
        dfs(root->right, rightnodes);
        return;
    }
};

int main()
{
    Solution solve;
    TreeNode* test = new TreeNode(1);
    test->left = new TreeNode(2);
    test->left->left = new TreeNode(3);
    test->right = new TreeNode(4);
    solve.flatten(test);
    cout << test->val << "," << test->right->val << "," << test->right->right->val<< endl;
}
