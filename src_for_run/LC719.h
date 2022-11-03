/*
Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
BinSearch
*/

#include "common.h"

class Solution719 {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back() - nums[0];
        int mid;
        int N = nums.size();
        
        auto getEnough = [&k, &nums, &N, &mid]() {
            int i = 0;
            int j = 0;
            int count = 0;
            while (i < N || j < N) {
                while (j < N && nums[j] - nums[i] <= mid) {
                    ++j;
                }
                count += j - 1 - i;
                if (count >= k) return true;
                ++i;
            }
            return count >= k;
        };
        
        while (left < right) {
            mid = (left + right) / 2;
            if (getEnough()) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
};