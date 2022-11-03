/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

#include "common.h"

class SolutionDP {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        int ans = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = dp[i] > ans ? dp[i] : ans;
        }
        return ans;
    }
};

class SolutionBiSearch {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub;
        for (int i = 0; i < n; ++i) {
            if (sub.empty() || nums[i] > sub.back()) {
                sub.push_back(nums[i]);
            } else {
                biSearch(sub, nums[i]);
            }
        }
        return sub.size();
    }
    
    void biSearch(vector<int>& vec, int target) {
        int left = 0;
        int right = vec.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (vec[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        vec[left] = target;
    }
};