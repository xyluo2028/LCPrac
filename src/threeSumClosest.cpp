// LCPrac33.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() == 3) return nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int tmpsum;
        int pt0;
        int pt1;
        int result = target + 10000000;
        for (size_t i = 0; i < nums.size()-2; i++)
        {
            pt0 = i + 1;
            pt1 = nums.size() - 1;
            while (pt0<pt1)
            {
                tmpsum = nums[i] + nums[pt0] + nums[pt1];
                cout << tmpsum << endl;
                if (tmpsum == target) return tmpsum;
                else if (tmpsum > target) pt1--;
                else if (tmpsum < target) pt0++;
                if (_dst(tmpsum, target) < _dst(result, target)) result = tmpsum;
                //else break;
            }
        }
        return result;
    }

private:
    int _dst(int a, int b) {
        return abs(a - b);
    }


};



int main()
{
    Solution solve;
    vector<int> test = { 2, 1, 4, 8, 16,128, 32, 64};
    int result = solve.threeSumClosest(test,82);
    cout << result << endl;
}


