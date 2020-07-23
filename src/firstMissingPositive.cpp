// LCPrac36.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 1;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i]>0)
            {
                if (nums[i] > result)return result;
                else result = nums[i] + 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution solve;
    vector<int> test = { 3,4,-1,1};
    int result = solve.firstMissingPositive(test);
    cout << result << endl;
}


