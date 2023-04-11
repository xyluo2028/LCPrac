// subtree of another tree
#include "common.h"

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class SolutionDFS {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (isIdentical(root, subRoot))return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right, subRoot);
    }

    bool isIdentical(TreeNode* n1, TreeNode* n2) {
        if (!n1 || !n2) {
            return !n1 && !n2;
        }
        if (n1->val != n2->val) return false;
        return isIdentical(n1->left, n2->left) && isIdentical(n1->right,n2->right);
    }
};

class SolutionPathMatch {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string subTpath = "";
        dfs(subRoot, subTpath);
        string rootPath = "";
        dfs(root, rootPath);
        if (rootPath.find(subTpath) != string::npos) return true;
        return false;
    }

    void dfs(TreeNode* root, string& path) {
        if (!root) {
            path += "n";
            return;
        }
        path += "m";
        path += to_string(root->val);
        //path += "l";
        dfs(root->left, path);
        //path += "r";
        dfs(root->right, path);
    }
};