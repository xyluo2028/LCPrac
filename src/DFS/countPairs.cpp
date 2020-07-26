struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}    
};

typedef TreeNode T;
class Solution {
public:
    int ans;
    int countPairs(TreeNode* root, int d) {
        if (root == nullptr) return 0;
        ans = 0;
        dfs(root, d);
        return ans;
    }

    vector<int> dfs(TreeNode* root, int d) {
        if (root->left == nullptr && root->right == nullptr) return { 0 };
        vector<int> leftitems;
        vector<int> rightitems;
        if (root->left != nullptr) leftitems = dfs(root->left, d);
        if (root->right != nullptr) rightitems = dfs(root->right, d);
        for (int i = 0; i < leftitems.size(); i++) leftitems[i]++;
        for (int j = 0; j < rightitems.size(); j++) rightitems[j]++;
        for (int i=0; i<leftitems.size(); i++)
        {
            for (int j=0; j<rightitems.size(); j++)
            {
                if (leftitems[i]+ rightitems[j] <= d) ans++;
            }
        }
        for (auto itemR:rightitems)
        {
            leftitems.push_back(itemR);
        }
        for (auto item:leftitems)
        {
            cout << item << ",";
        }
        cout << endl;
        return leftitems;
    }
};
