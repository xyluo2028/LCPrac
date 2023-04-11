// Best Time to Buy and Sell Stock with Cooldown
#include "common.h"

class Solution {
public:
    int _len;
    int maxProfit(vector<int>& prices) {
        _len = prices.size();
        unordered_map<int, unordered_map<bool, int>> memo;
        return recur_with_memo(memo, prices, 0, true);
    }
    // state: true = buying; false = not buying
    int recur_with_memo(unordered_map<int, unordered_map<bool, int>>& memo, vector<int>& prices, int idx, int state) {
        if (idx >= _len) return 0;
        if (memo[idx].count(state) > 0) return memo[idx][state];
        int ans = 0;
        if (state) {
            int buying = recur_with_memo(memo, prices, idx + 1, !state) - prices[idx]; // buy now
            int cooldown = recur_with_memo(memo, prices, idx + 1, state);
            ans = buying > cooldown ? buying : cooldown;
        } else {
            int selling = recur_with_memo(memo, prices, idx + 2, !state) + prices[idx]; // sell now
            int cooldown = recur_with_memo(memo, prices, idx + 1, state);
            ans = selling > cooldown ? selling : cooldown;
        }
        memo[idx][state] = ans;
        return ans;
    }
};