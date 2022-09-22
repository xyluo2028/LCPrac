/*
For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].
Input: n = 3, k = 1
Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
*/

#include "common.h"

class Solution {
public:
    const int MOD = 1e9 + 7;
    int kInversePairs(int n, int k) {
        if (k > n * (n - 1) / 2) return 0;
        if (k == 0) return 1;
        vector<vector<int>> dp;
        vector<int> row1(k + 1);
        for (int i = 0; i <= k; ++i) {
            row1[i] = (i == 0 ? 1 : 0);
        }
        //cout << "debug" << endl;
        dp.push_back(row1);
        for (int i = 1; i < n; ++i) {
            vector<int> tmp_vec(k + 1);
            tmp_vec[0] = 1;
            for (int j = 1; j <= k; ++j) {
                if (j - i <= 0) {
                    tmp_vec[j] = (tmp_vec[j - 1] + dp[i-1][j]) % MOD;
                } else {
                    int tmp_big = (dp[i-1][j] + MOD - dp[i - 1][j - i - 1]) % MOD;
                    tmp_vec[j] = (tmp_vec[j - 1] + tmp_big) % MOD;
                }                
            }
            dp.push_back(tmp_vec);
        }
        int ans = dp[n-1][k];
        return ans;
    }
};