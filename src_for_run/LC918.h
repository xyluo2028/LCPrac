// Maximum Sum Circular Subarray
#include "common.h"

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSum = nums[0];
        int maxSum = nums[0];
        int sum = 0;
        int cur_max = 0;
        int cur_min = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            cur_max = max(0, cur_max) + nums[i];
            maxSum = max(maxSum, cur_max);
            cur_min = min(0, cur_min) + nums[i];
            minSum = min(minSum, cur_min);
            sum += nums[i];
        }
        return sum == minSum ? maxSum : max(maxSum, sum - minSum);
    }
};