/*
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation: 
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6

the use of multiset, iterator, next(iterator)
*/

#include "common.h"

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<int> mSet(nums.begin(), nums.begin() + k);
        bool isOdd = (k % 2 == 1);
        multiset<int>::iterator iter = mSet.begin();
        if (isOdd) {
            double tmp = *next(mSet.begin(), k / 2);
            ans.push_back(tmp);
        } else {
            double tmp = (double)*next(mSet.begin(), k / 2 - 1) + *next(mSet.begin(), k / 2);
            tmp *= 0.5;
            ans.push_back(tmp);
        }
        
        for (int i = 1; i <= nums.size() - k; ++i) {
            auto iter = mSet.find(nums[i - 1]);
            mSet.erase(iter);
            mSet.insert(nums[i + k - 1]);
            if (isOdd) {
                double tmp = *next(mSet.begin(), k / 2);
                ans.push_back(tmp);
            } else {
                double tmp = (double)*next(mSet.begin(), k / 2 - 1) + *next(mSet.begin(), k / 2);
                tmp *= 0.5;
                ans.push_back(tmp);
            }
        }
    }
};