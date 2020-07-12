#include <iostream>
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        bool flag = false;
        result.push_back(root->val);
        if (root->left == NULL && root->right == NULL) return result;
        if (root->left != NULL) {
            findleftedge(root->left, result, flag);
            result.pop_back();
        }
        findleaves(root, result);
        
        if (root->right != NULL) {
            flag = false;
            result.pop_back();
            findrightedge(root->right, result, flag);
        }
        return result;
    }

private:
    void findleaves(TreeNode* root, vector<int>& nodes) {
        if (root->left == NULL && root->right == NULL) {
            nodes.push_back(root->val);
            return;
        }
        if (root->left != NULL) findleaves(root->left, nodes);
        if (root->right != NULL)findleaves(root->right, nodes);
        return;
    }
    void findleftedge(TreeNode* root, vector<int>& nodes, bool& flag) {
        if (flag) return;
        nodes.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            flag = true;
            return;
        }
        if (root->left != NULL) findleftedge(root->left, nodes, flag);
        if (root->right != NULL) findleftedge(root->right, nodes, flag);
    }

    void findrightedge(TreeNode* root, vector<int>& nodes, bool& flag) {
        if (flag) return;
        if (root->left == NULL && root->right == NULL) {
            nodes.push_back(root->val);
            flag = true;
            return;
        }
        if (root->right != NULL) findrightedge(root->right, nodes, flag);
        if (root->left != NULL) findrightedge(root->left, nodes, flag);
        if (flag) {
            nodes.push_back(root->val);
            return;
        }
    }

};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);
    Solution solve;
    vector<int> result = solve.boundaryOfBinaryTree(root);
    for (auto item : result)
    {
        cout << item << endl;
    }
    
}


