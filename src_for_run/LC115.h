// Distinct Subsequences
/*
Input: s = "rabbbit", t = "rabbit"
Output: 3
*/
#include "common.h"

class Solution {
public:
    int n_s;
    int n_t;
    string _s;
    string _t;
    int numDistinct(string s, string t) {
        n_s = s.size();
        n_t = t.size();
        _s = s;
        _t = t;
        vector<vector<int>> cache(n_s, vector<int>(n_t, -1));
        return dfs(0, 0, cache);
    }
    int dfs(int i, int j, vector<vector<int>>& cache) {
        if (j == n_t) return 1;
        if (i == n_s) return 0;
        if (cache[i][j] >= 0) return cache[i][j];
        int ans = 0;
        if (_s[i] == _t[j]) {
            ans = dfs(i + 1, j + 1, cache) + dfs(i + 1, j, cache);
        } else {
            ans = dfs(i + 1, j, cache);
        }
        cache[i][j] = ans;
        return ans;
    }
};