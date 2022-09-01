/*
get the min/max produc MUST INCLUDING the current nums[i]!
*/

#include "common.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() < 2) return nums[0];
        int N = nums.size();
        int max0 = nums[0];
        int max1 = nums[0];
        int min0 = nums[0];
        int min1 = nums[0];
        int ans = nums[0];
        for (int i = 1; i < N; ++i) {
            max0 = max(max(nums[i]*max1, nums[i]*min1), nums[i]);
            min0 = min(min(nums[i]*min1, nums[i]*max1), nums[i]);
            max1 = max0;
            min1 = min0;
            ans = max0 > ans ? max0 : ans;
        }
        return ans;
    }
};