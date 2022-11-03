/*
Input: nums = [2,4,-2], k = 5
Output: 2
Explanation: All the possible subsequence sums that we can obtain are the following sorted in decreasing order:
- 6, 4, 4, 2, 2, 0, 0, -2.
The 5-Sum of the array is 2.
*/
#include "common.h"

class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        sort(begin(nums), end(nums), [](int a, int b){ return abs(a) < abs(b); });
        long long res = accumulate(begin(nums), end(nums), 0LL, [](long long sum, int n){ return sum + max(0, n); });
        priority_queue<pair<long long, int>> pq;
        pq.push({res - abs(nums[0]), 0});
        while (--k) {
            //auto [sum, i] = pq.top();
            auto sum = pq.top().first;
            auto i = pq.top().second;
            pq.pop();
            if (i < nums.size() - 1) {
                pq.push({sum - abs(nums[i + 1]), i + 1});
                pq.push({sum + abs(nums[i]) - abs(nums[i + 1]), i + 1});
            }
            res = sum;
        }
        return res;
    }
};