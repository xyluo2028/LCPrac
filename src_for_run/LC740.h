// Delete and Earn
#include "common.h"

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> omap;
        for (int& num : nums) {
            omap[num]++;
        }
        vector<int> vec;
        for (auto&p : omap) {
            vec.push_back(p.first);
        }
        unordered_map<int, int> memo;
        return recur(vec, omap, memo, 0);
    }

    int recur(vector<int>& vec, map<int, int>& omap, unordered_map<int, int>& memo, int idx) {
        if (idx == vec.size()) {
            return 0;
        }
        if (memo.count(idx) > 0) {
            return memo[idx];
        }
        int ans = -1;
        if (idx < vec.size() - 1 && vec[idx] + 1 == vec[idx + 1]) {
            int tmp0 = vec[idx] * omap[vec[idx]] + recur(vec, omap, memo, idx + 2);
            int tmp1 = recur(vec, omap, memo, idx + 1);
            ans = tmp0 > tmp1 ? tmp0 : tmp1;
        } else {
            ans = vec[idx] * omap[vec[idx]] + recur(vec, omap, memo, idx + 1);
        }
        memo[idx] = ans;
        return ans;
    }
};