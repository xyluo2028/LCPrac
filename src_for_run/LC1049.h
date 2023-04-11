//Last Stone Weight II 2D-dp
#include "common.h"

class Solution {
public:
    int sum;
    int n;
    int lastStoneWeightII(vector<int>& stones) {
        sum = accumulate(stones.begin(), stones.end(), 0);
        n = stones.size();
        vector<vector<int>> memo(n, vector<int>(sum, -1));
        return recur(stones, memo, 0, 0);
    }
    int recur(vector<int>& stones, vector<vector<int>>& memo, int idx, int cur_sum) {
        if (idx >= n) {
            return abs(2 * cur_sum - sum);
        }
        if (memo[idx][cur_sum] >= 0) return memo[idx][cur_sum];
        int ans1 = recur(stones, memo, idx + 1, cur_sum + stones[idx]);
        int ans2 = recur(stones, memo, idx + 1, cur_sum);
        int ans = ans1 < ans2 ? ans1 : ans2;
        memo[idx][cur_sum] = ans;
        return ans;
    }
};