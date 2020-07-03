// LCPrac22.cpp : This file contains the 'main' function. Program execution begins and ends there.
// [-2,1,-3,4,-1,2,1,-5,4] dp, divide & conquer

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = nums.size();
        vector<int> dp(len);
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < len; i++) {
            dp[i] = nums[i] + dp[i - 1] > nums[i] ? nums[i] + dp[i - 1] : nums[i];
            if (dp[i] > result) result = dp[i];
        }
        return result;
    }
};

int main()
{
    Solution solve;
    vector<int> test = { -2,1,-3,4,-1,2,1,-5,4 };
    int result = solve.maxSubArray(test);
    cout << result << endl;
}


