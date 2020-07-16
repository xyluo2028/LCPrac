// LCWorkebench.cpp : This file contains the 'main' function. Program execution begins and ends there.
//   3
//  / \
// 9  20
//    / \
//  15   7
//  [
//    [3],
//    [20, 9],
//    [15, 7]
//  ]


#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;



struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        deque<TreeNode*> dQ;
        dQ.push_front(root);
        vector<int> tmp;
        map<TreeNode*, int> layers;
        int layer = 0;
        layers.emplace(root, layer);
        while (!dQ.empty())
        {
            if (layers[dQ.front()] == layer && (layer==0 || layer % 2 == 1)) {
                tmp.push_back(dQ.front()->val);
                if (dQ.front()->right != NULL) {
                    dQ.push_back(dQ.front()->right);
                    layers.emplace(dQ.front()->right, layer + 1);
                }
                if (dQ.front()->left != NULL) {
                    dQ.push_back(dQ.front()->left);
                    layers.emplace(dQ.front()->left, layer + 1);
                }
                dQ.pop_front();
            }
            else if (layers[dQ.back()] == layer && layer % 2 == 0) {
                tmp.push_back(dQ.back()->val);
                if (dQ.back()->left != NULL) {
                    dQ.push_front(dQ.back()->left);
                    layers.emplace(dQ.back()->left, layer + 1);
                }
                if (dQ.back()->right != NULL) {
                    dQ.push_front(dQ.back()->right);
                    layers.emplace(dQ.back()->right, layer + 1);
                }
                dQ.pop_back();
            }
            else {
                layer++;
                result.push_back(tmp);
                tmp.clear();
            }

        }
        result.push_back(tmp);
        return result;
    }

};


int main()
{
    Solution solve;
    TreeNode* node0 = new TreeNode(3);
    node0->left = new TreeNode(9);
    node0->right = new TreeNode(20);
    node0->left->left = new TreeNode(12);
    node0->left->right = new TreeNode(13);
    node0->right->left = new TreeNode(15);
    node0->right->right = new TreeNode(7);
    node0->left->left->left = new TreeNode(22);
    node0->left->left->right = new TreeNode(26);
    node0->right->right->left = new TreeNode(31);
    node0->right->right->right = new TreeNode(36);
    vector<vector<int>> result = solve.zigzagLevelOrder(node0);
    for (auto item : result) {
        for (auto elem:item)
        {
            cout << elem << ", ";
        }
        cout << endl;
    }
}
