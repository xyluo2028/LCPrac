
/*
BFS
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

class Solution103 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<TreeNode*> myQ;
        myQ.push(root);
        vector<int> tmp;
        bool isEven = true;
        while (!myQ.empty())
        {
            tmp.clear();
            int layer_len = myQ.size();
            for (int i = 0; i < layer_len; i++) {
                TreeNode* tempN= myQ.front();
                myQ.pop();
                tmp.push_back(tempN->val);
                if (tempN->left) {
                    myQ.push(tempN->left);
                }
                if (tempN->right) {
                    myQ.push(tempN->right);
                }
            }
            result.push_back(tmp);
        }
        for(auto& layer:result) {   // reference!! or the layer was not changed
            if (!isEven) {
                reverse(layer.begin(), layer.end());
            }
            isEven = !isEven;
        }
        return result;        
    }
};