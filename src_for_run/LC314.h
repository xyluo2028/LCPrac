#include "common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution314 {
    
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        map<int, list<int>> mHash;   // map can be use with list
        //mHash[0].push_back(root->val);
        queue<pair<TreeNode*, int>> mQ;   // trick, the pair.second represents the column index of TreeNode(pair.first)
        mQ.push({root, 0});
        while(!mQ.empty()) {
            int qSize = mQ.size();
            for (int i = 0; i < qSize; ++i) {
                auto tmpP = mQ.front();
                mHash[tmpP.second].push_back(tmpP.first->val);
                if (tmpP.first->left) {
                    mQ.push({tmpP.first->left, tmpP.second - 1});
                }
                if (tmpP.first->right) {
                    mQ.push({tmpP.first->right, tmpP.second + 1});
                }
                mQ.pop();
            }
        }
        int idx = 0;
        for (auto& item : mHash) {
            ans.push_back({});
            while(!item.second.empty()) {
                ans[idx].push_back(item.second.front());
                item.second.pop_front();
            }
            ++idx;
        }
        return ans;
    }
};