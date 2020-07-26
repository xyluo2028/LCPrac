#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class TreeNode0 {
public:
    TreeNode0(int val,int idx) {
        value = val;
        index = idx;
    }
    int value;
    int index;
    vector<TreeNode0*> conected;
};

class Solution {
public:
    vector<int> result;
    vector<bool> visited;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<TreeNode0*> Tree(n);
        visited.assign(n, false);
        result.assign(n, 0);
        vector<int> tables(26);
        for (size_t i = 0; i < n; i++)
        {
            Tree[i] = new TreeNode0(chartoint(labels[i]), i);
        }
        for (auto edg : edges)
        {
            Tree[edg[0]]->conected.push_back(Tree[edg[1]]);
            Tree[edg[1]]->conected.push_back(Tree[edg[0]]);
        }

        dfs(Tree, 0, tables);

        return result;
    }
private:
    int chartoint(char letter) {
        return (int)letter - 97;
    }
    void dfs(vector<TreeNode0*>& Tree,  int idx, vector<int>& table) {
        if (visited[idx]) return;
        visited[idx] = true;
        vector<int> tmp(26,0);
        for (auto node : Tree[idx]->conected) {
            dfs(Tree, node->index, tmp);
        }
        result[idx] = ++tmp[Tree[idx]->value];
        for (int i = 0; i < 26; ++i) table[i] += tmp[i];
    }
};
