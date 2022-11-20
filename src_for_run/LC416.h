// Partition Equal Subset Sum
/*
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/
#include "common.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for (auto& num : nums) {
            target += num;
        }
        if (target % 2 != 0) return false;
        target *= 0.5;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = target; j >= nums[i-1]; --j) {
                dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }
        return dp[target];
    }
};