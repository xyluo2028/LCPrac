// Matchsticks to Square
#include "common.h"

class Solution {
public:
    vector<int> edges;
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
        int edge = sum / 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());  // optimization 
        if (matchsticks.back() > edge) return false;
        edges.resize(4, edge);
        return backtrack(matchsticks, 0);
    }

    bool backtrack(vector<int>& matchsticks, int idx) {
        if (idx == matchsticks.size()) {
            return true;
        }
        for (int i = 0; i < 4; ++i) {
            int j = i;
            while (--j >= 0) {
                if (edges[j] == edges[i]) break;  // optimization 
            }
            if (j >= 0) continue;
            if (edges[i] >= matchsticks[idx]) {
                edges[i] -= matchsticks[idx];
                if (backtrack(matchsticks, idx + 1)) {
                    return true;
                }
                edges[i] += matchsticks[idx];
            }
        }
        return false;
    }
};