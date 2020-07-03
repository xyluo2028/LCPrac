// LCPrac27.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // return TreeNode*;  TreeNode* target
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL || _isleaf(root)) return NULL;
        TreeNode* result = NULL;
        stack<TreeNode*> nodebox;
        vector<TreeNode*> nodevec;
        int idx = 0;
        while (!nodebox.empty() || root != NULL)
        {
            if (root != NULL) {
                nodebox.push(root);
                root = root->left;
            }
            else {
                root = nodebox.top();
                if (p->val == root->val) {
                    idx = nodevec.size();
                }
                nodevec.push_back(nodebox.top());
                nodebox.pop();
                cout << root->val << endl;
                root = root->right;
            }
        }
        if (idx+1==nodevec.size())
        {
            return NULL;
        }
        else return nodevec[idx+1];
    }

private:
    bool _isleaf(TreeNode* p) {
        if (p->left == NULL && p->right == NULL) return true;
        else return false;
    }

};

int main()
{
    TreeNode* test = new TreeNode(4);
    test->left = new TreeNode(2);
    test->right = new TreeNode(5);
    test->left->left = new TreeNode(1);
    test->left->right = new TreeNode(3);
    TreeNode* target = test->right;
    Solution solve;
    TreeNode* result = solve.inorderSuccessor(test, target);
    if(result != NULL) cout << result->val << endl;
}


