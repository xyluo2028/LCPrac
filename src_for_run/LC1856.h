// Maximum Subarray Min-Product mono stack
#include "common.h"

class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<long long> prefSum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefSum[i] = nums[i-1] + prefSum[i-1];
        }
        stack<int> mstk;
        mstk.push(-1);
        for (int i = 0; i <= n; ++i) {
            while (mstk.top() >= 0 && (i == n || nums[mstk.top()] > nums[i] )) {
                int topi = mstk.top();
                mstk.pop();
                long long tmp = (prefSum[i] - prefSum[mstk.top() + 1]) * nums[topi];
                ans = tmp > ans ? tmp : ans;
            }
            mstk.push(i);
        }
        return (int)(ans % MOD);
    }
};