/*
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
2D dp
*/

#include "common.h"

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp = vector<vector<int>>(m , {vector<int>(n, 0)});
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums2[i] != nums1[j]) continue;
                if (j - 1 >= 0 && i - 1 >= 0) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = 1;
                }
                ans = dp[i][j] > ans ? dp[i][j] : ans;
            }
        }
        return ans;
    }
};