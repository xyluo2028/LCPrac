/*
Subarray Sum Equals K, use hashmap, O(n)
*/

#include "common.h"

class Solution560 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        unordered_map<int, int> mHash;
        mHash[0]++;
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += nums[i];
            if (mHash.find(sum - k) != mHash.end()) {
                ans += mHash[sum-k];
            }
            mHash[sum]++;
        }
        return ans;
    }
};