/*
sliding window
Input: nums = [2,1,3], k = 4
Output: 3
Explanation: The subarrays of [2,1,3] are:
- [2] with sum 2
- [1] with sum 1
- [3] with sum 3
- [2,1] with sum 3
- [1,3] with sum 4
- [2,1,3] with sum 6 
Ordering the sums from smallest to largest gives 1, 2, 3, 3, 4, 6. The 4th smallest is 3.
 */

#include "common.h"

class Solution1918 {
public:
    int kthSmallestSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 1000000000;

        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0;
            int i = 0;
            int j = 0;
            int sum = 0;
            while (i < n) {
                sum += nums[i++];
                while (sum > mid) {
                    sum -= nums[j++];
                }
                count += i - j;
            }
            if (count >= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};