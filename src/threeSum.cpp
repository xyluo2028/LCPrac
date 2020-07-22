// LCPrac35.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        vector<int> tmp(3);
        int len = nums.size();
        int front;
        int back;
        sort(nums.begin(), nums.end());
        int cache;
        for (int i = 0; i < len-2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            front = i + 1;
            back = len-1;
            cache = nums[i] - 100;
            while (front < back)
            {
                if (nums[front] + nums[back] > -nums[i]) back--;
                else if (nums[front] + nums[back] < -nums[i]) front++;
                else {
                        tmp[0] = nums[i];
                        tmp[1] = nums[front];
                        tmp[2] = nums[back];
                        if (cache!=tmp[1]) {
                            result.push_back(tmp);
                            cache = tmp[1];
                        }
                        back--;
                        front++;
                 }
            }
        }
        return result;
    }
};

int main()
{
    Solution solve;
    vector<int> test = { -1, 0, 1, 2, -1, -4 };
    vector<vector<int>> result = solve.threeSum(test);
    cout << result[0][0] << ", " << result[0][1]  << endl;
}


